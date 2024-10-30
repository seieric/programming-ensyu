#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("[ERROR] Expected 2 arguments.");
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("[ERROR] Unable to open input file");
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (out == NULL)
    {
        printf("[ERROR] Unable to open output file.");
        fclose(in);
        return 1;
    }

    char c;
    int is_start = 1;
    int maybe_i = 0;
    char prev = 0;
    while ((c = fgetc(in)) != EOF)
    {
        // 先頭文字を大文字にする
        if (c == '.')
        {
            is_start = 1;
        }
        else if (is_start && 'a' <= c && c <= 'z')
        {
            c += 'A' - 'a';
            is_start = 0;
        }

        // 一人称を大文字にする
        if (maybe_i)
        {
            maybe_i = 0;
            if (c == ' ')
            {
                fputc('I', out);
            }
            else
            {
                fputc('i', out);
            }
        }
        if (prev == ' ' && c == 'i')
        {
            c = 0;
            maybe_i = 1;
        }

        prev = c;
        if (c)
            fputc(c, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}