#include <stdio.h>

int main()
{
    for (int x = 1; x < 1000; x++)
    {
        for (int y = x; y < 1000; y++)
        {
            int sum = x * x + y * y;
            for (int z = 1; z < 1000; z++)
            {
                if (sum == z * z)
                {
                    printf("%d^2 + %d^2 = %d^2\n", x, y, z);
                }
            }
        }
    }
    return 0;
}