#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *buf;
    int n = 0;

    if (argc == 3)
    {
        strcpy(buf, argv[1]);
        n = atoi(argv[2]);
    }

    for (int i = 0; i < n; i++)
        printf("%s ", buf);

    return 0;
}