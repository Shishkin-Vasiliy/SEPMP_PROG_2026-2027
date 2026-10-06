#include <stdio.h>

int main(void)
{
    for (int code = 32; code <= 126; code++)
        printf("Symbol = %c, Code = %d\n", code, code);

    return 0;
}