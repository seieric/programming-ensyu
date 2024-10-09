#include <stdio.h>
#include <math.h>
int is_prime(int n);

int main(void)
{
    double tmp = 1;
    int max = 10000000;

    for (int i = 2; i < max; i++)
    {
        if (is_prime(i) == 1)
        {
            tmp *= 1 - 1.0 / pow(i, 2);
        }
    }

    double pi = sqrt(6 / tmp);
    printf("%f\n", pi);
}

int is_prime(int n)
{
    int result = 1;
    int max = fabs(sqrt(n));
    for (int i = 2; i <= max; i++)
    {
        if (n % i == 0)
        {
            result = 0;
            break;
        }
    }
    return result;
}