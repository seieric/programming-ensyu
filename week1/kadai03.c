#include <stdio.h>

int main()
{
    int n = 158340421;
    for (int i = 0; i < n / 2; i++)
    {
        if (i * i * i == n)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}