#include <stdio.h>
double legendre(int n, double x);

// legendre(128, 0.5)等を計算するにはメモ機構が必要

int main(void)
{
    double v = legendre(16, 0.5);
    printf("%f\n", v);
    v = legendre(32, 0.7);
    printf("%f\n", v);
    return 0;
}

double legendre(int n, double x)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return x;
    }
    return ((2 * n - 1) * x * legendre(n - 1, x) - (n - 1) * legendre(n - 2, x)) / n;
}