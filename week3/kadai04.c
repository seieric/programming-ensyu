#include <stdio.h>
#include <math.h>
int mod_apm(int a, int p, int m);
int mod(int a, int b);

int main(void)
{
    int a = 541;
    int p = 1234;
    int m = 1299709;
    int s = mod_apm(a, p, m);
    printf("%d^%d mod %d = %d\n", a, p, m, s);
    return 0;
}

int mod_apm(int a, int p, int m)
{
    if (p == 1)
    {
        return mod(a, m);
    }
    return mod(a * mod_apm(a, p - 1, m), m);
}

int mod(int a, int b)
{
    return a % b;
}