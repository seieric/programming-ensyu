#include <stdio.h>
#include <string.h>

void uppercase(char *s);

int main()
{
    char s[] = "hello world";
    uppercase(s);
    printf("%s\n", s); // 出力は"HELLO WORLD"
    return 0;
}

void uppercase(char *s)
{
    int length = strlen(s);
    for (int i = 0; i < length; ++i)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
        }
    }
}