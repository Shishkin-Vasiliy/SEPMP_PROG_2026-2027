#include <stdio.h>

double power(int n);
int main(void)
{
    int i = 1;
    int n = 1000;
    double pi = 0;

    for (; i < n; i++)
    {
        pi += (power(i + 1) / (2 * i - 1)); 
    }

    pi *= 4.0;
    printf("pi = %lg\n", pi);

    return 0;
}

double power(int n)
{
    return (n % 2 == 0) ? 1.0 : -1.0;
}