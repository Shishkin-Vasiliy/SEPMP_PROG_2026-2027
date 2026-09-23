#include <stdio.h>

int main(void)
{
    int n = 0, k = 0;
    unsigned long long int A = 1;
    scanf("%d %d", &n, &k);

    for (int i = 0; i <= k - 1; i++)
    {
        A *= (n - i);
    }
    
    printf("A(^%d_%d) = %llu\n", k, n, A);

    return 0;
}

