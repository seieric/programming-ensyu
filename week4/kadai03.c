#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s);

int main()
{
    char s[] = "hello";
    reverse(s);
    printf("%s\n", s); // 出力は"olleh"
    return 0;
}

void reverse(char *s)
{
    int length = strlen(s);
    char *tmp = (char *)malloc(sizeof(char) * (length + 1));
    strcpy(tmp, s);
    for (int i = 0; i < length; ++i)
    {
        s[i] = tmp[length - 1 - i];
    }
    free(tmp);
}