#include <stdio.h>

unsigned long long int fact(int n);
int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("fact(%d) = %llu", n, fact(n));

    return 0;
}

unsigned long long int fact(int n)
{
    unsigned long long int fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    return fact;
}