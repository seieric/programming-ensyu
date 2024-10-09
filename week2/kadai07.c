#include <stdio.h>
#include <math.h>
int is_prime(int n);
int main(void)
{
    for (int i = 4; i <= 1000; i += 2)
    {
        int solved = 0;
        for (int j = 2; j < i; j++)
        {
            if (is_prime(j) == 1)
            {
                int k = i - j;
                if (is_prime(k) == 1)
                {
                    printf("%d = %d + %d\n", i, j, k);
                    solved = 1;
                    break;
                }
            }
        }
        if (solved == 0)
        {
            printf("Something went wrong.\n");
            return 1;
        }
    }
    return 0;
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