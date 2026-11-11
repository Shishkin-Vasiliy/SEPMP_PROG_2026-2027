#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if (size > 3)
    {
        fseek(fp, -3, SEEK_END);
    }
    else
    {
        fseek(fp, 0, SEEK_SET);
    }

    int c;
    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);
    return 0;
}