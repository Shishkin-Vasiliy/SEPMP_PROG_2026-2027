#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10000

struct Number {
    int num;
    int digit_sum;
};

int sum_cmpr(const void *a, const void *b);
int digit_sum(int n);

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    struct Number buf[BUF_SIZE] = {};

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(buf[i].num));
        buf[i].digit_sum = digit_sum(buf[i].num);
    }

    qsort(buf, n, sizeof(struct Number), sum_cmpr);

    for (int i = 0; i < BUF_SIZE; i++)
        printf("%d ", buf[i].num);

    return 0;
}

int sum_cmpr(const void *a, const void *b)
{
    const struct Number *A = (const struct Number *)a;
    const struct Number *B = (const struct Number *)b;

    return A -> digit_sum - B -> digit_sum;
}

int digit_sum(int n)
{
    int digit_sum = 0;
    if (n < 0)
        n = -n;

    while (n > 0)
    {
        digit_sum += n % 10;
        n /= 10;
    }

    return digit_sum;
}

