#include <stdio.h>

void alice(int n);
void bob(int n);
int main(void)
{
    int n = 0;
    
    scanf("%d", &n);
    alice(n);

    return 0;
}

void alice(int n)
{
    if (n % 2 == 0)
        return;

    n = 3 * n + 1;
    printf("Alice: %d\n", n);

    bob(n);
}

void bob(int n)
{
    if (n % 2 != 0)
        return;

    while (n % 2 == 0)
    {
        n /= 2;
        printf("Bob: %d\n", n);
    }

    if (n == 1)
        return;

    alice(n);
}