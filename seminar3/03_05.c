#include <stdio.h>

#define MAX_LINE 100

int main(void)
{
    char s[MAX_LINE] = {0};
    unsigned int n = 0;

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        n += (s[i] - '0');
    }
    printf("n = %u\n", n);

    return 0;
}