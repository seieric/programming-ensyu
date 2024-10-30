#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count_rows(FILE *fp);
void calc_and_print(double *nums, int len, char *label);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("[ERROR] Expected 1 arguments.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open file.\n");
        return 1;
    }

    int num_rows = count_rows(fp);

    double *ages = (double *)malloc(sizeof(double) * num_rows);
    double *heights = (double *)malloc(sizeof(double) * num_rows);
    double *weights = (double *)malloc(sizeof(double) * num_rows);
    int res, num_records = 0;

    while (EOF !=
           (res = fscanf(fp, "%*[^,],%lf,%lf,%lf", &ages[num_records], &heights[num_records], &weights[num_records])))
    {
        if (res != 3)
        {
            printf("[ERROR] Number of columns does not match.\n");
            return 1;
        }
        ++num_records;
    }

    fclose(fp);

    calc_and_print(ages, num_records, "Age");
    calc_and_print(heights, num_records, "Height");
    calc_and_print(weights, num_records, "Weight");

    return 0;
}

int count_rows(FILE *fp)
{
    int count = 1;
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
            ++count;
    }
    fseek(fp, 0L, SEEK_SET);
    return count;
}

void calc_and_print(double *nums, int len, char *label)
{
    double max, min, sum, mean, stdev;
    max = min = sum = nums[0];
    for (int i = 1; i < len; ++i)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
        else if (nums[i] < min)
        {
            min = nums[i];
        }
        sum += nums[i];
    }
    mean = sum * 1.0 / len;

    double square_sum = 0;
    for (int i = 0; i < len; ++i)
    {
        double dist = nums[i] - mean;
        square_sum += dist * dist;
    }
    stdev = sqrt(square_sum);
    printf("%s : (max,min,mean,stdev) = (%lf, %lf, %lf, %lf)\n", label, max, min, mean, stdev);
}