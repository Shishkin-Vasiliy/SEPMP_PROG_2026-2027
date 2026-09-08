#include <stdio.h>

int main(void)
{
    int n = 0;
    int i = 0;

    while(scanf("%d", &n) != 1)
        ;

    int buf[n] = {};

    for (; i < n; i++)
        scanf("%d", buf + i);

    for (i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            printf("%d ", buf[j]);

    return 0;
}