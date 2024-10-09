#include <stdio.h>
#include <math.h>

int main(void)
{
    double pi;
    double sum = 0;
    int max = 100000000;

    for (int n = 1; n < max; n++)
    {
        sum += 1 / (pow(n, 2) * pow(2, n - 1));
    }

    pi = sqrt(6 * (sum + pow(log(2), 2)));
    printf("%f\n", pi);
    return 0;
}