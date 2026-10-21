#include <stdio.h>

int Sum(int n, int m);
int Pow(int n);

int main(void)
{
    int n = 0;
    int m = 0;
    int sum = 0;

    while (scanf("%d %d", &n, &m) == 2)
    {
        sum = Sum(n, m);
        printf("sum = %d\n", sum);
    }

    return 0;
}

// возводит -1 в степень n
int Pow(int n)
{
    if (n % 2 == 0)
        return 1;
    else 
        return -1;
}
 
int Sum(int n, int m)
{
    int i = 1;
    int j = 1;
    int sum = 0;

    for (; i <= n; i++)
    {
        for (; j <= m; j++)
            sum += Pow(i + j) * i * j;

        j = 1;
    } 
    return sum;
}



