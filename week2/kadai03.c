#include <stdio.h>
#include <math.h>
int is_prime(int n);

int main()
{
    for (int i = 2; i <= 1000; i++)
    {
        if (is_prime(i) == 1)
        {
            printf("%d is prime\n", i);
        }
    }
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