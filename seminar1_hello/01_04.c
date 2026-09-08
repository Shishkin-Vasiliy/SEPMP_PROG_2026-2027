#include <stdio.h>

int main(void)
{
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
        printf("%3d -> %3d -> %3d\n", n, n * n, n * n * n);

    return 0;
}