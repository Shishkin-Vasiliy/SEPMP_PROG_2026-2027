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

    printf("%ld\n", size);

    fclose(fp);
    return 0;
}