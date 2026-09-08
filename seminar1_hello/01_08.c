#include <stdio.h>

int main(void)
{
    int n = 0;
    int temp = 0;

    int a = 0, b = 0, c = 0;

    scanf("%d %d %d", &a, &b, &c);

    temp = a % c;
    n = a + c - temp;

    while (n <= b)
    {
        printf("%d ", n);
        n = n + c;
    }

    return 0;
}