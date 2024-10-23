#include <stdio.h>

int roman2num(char *);
void process_num(int num, int *result, int *prev);

int main()
{
    // Examples
    printf("XIV = %d\n", roman2num("XIV"));             // 14
    printf("CDXCV = %d\n", roman2num("CDXCV"));         // 495
    printf("MCMXLV = %d\n", roman2num("MCMXLV"));       // 1945
    printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX")); // 3999
    return 0;
}

int roman2num(char *s)
{
    int prev = 10000000;
    int result = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        switch (s[i])
        {
        case 'I':
            process_num(1, &result, &prev);
            break;
        case 'V':
            process_num(5, &result, &prev);
            break;
        case 'X':
            process_num(10, &result, &prev);
            break;
        case 'L':
            process_num(50, &result, &prev);
            break;
        case 'C':
            process_num(100, &result, &prev);
            break;
        case 'D':
            process_num(500, &result, &prev);
            break;
        case 'M':
            process_num(1000, &result, &prev);
            break;
        default:
            break;
        }
    }
    return result;
}

void process_num(int num, int *result, int *prev)
{
    *result += num;
    if (*prev < num)
    {
        *result -= *prev * 2;
    }
    *prev = num;
}