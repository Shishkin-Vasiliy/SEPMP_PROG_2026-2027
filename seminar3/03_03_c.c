#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    scanf("%c", &c);

    if (isalpha((unsigned char)c))
        printf("Letter\n");
    else if (isdigit((unsigned char)c))
        printf("Digit\n");
    else
        printf("Other\n");

    return 0;
}