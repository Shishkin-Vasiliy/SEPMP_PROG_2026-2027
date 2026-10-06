#include <stdio.h>

int main(void)
{
    char c;
    scanf("%c", &c);

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        putchar('L'), putchar('e'), putchar('t'), putchar('t'), putchar('e'), putchar('r'), putchar('\n');
    else if (c >= '0' && c <= '9')
        putchar('D'), putchar('i'), putchar('g'), putchar('i'), putchar('t'), putchar('\n');
    else
        putchar('O'), putchar('t'), putchar('h'), putchar('e'), putchar('r'), putchar('\n');

    return 0;
}