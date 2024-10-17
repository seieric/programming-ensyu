#include <stdio.h>
double sqrt_cf(double);
double K(double, int);

int main(void)
{
    double z = 2;
    double s = sqrt_cf(z);
    printf("%f\n", s);
    return 0;
}

double sqrt_cf(double z)
{
    return 1.0 + K(z, 0);
}

double K(double z, int depth)
{
    if (depth > 10)
    {
        return 0;
    }
    return (z - 1) / (2 + K(z, depth + 1));
}