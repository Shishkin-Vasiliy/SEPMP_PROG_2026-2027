#include <stdio.h>

int main(void)
{
    char *s;
    unsigned int n = 0;

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        n += (s[i] - '0');
    }
    printf("n = %u\n", n);

    return 0;
}