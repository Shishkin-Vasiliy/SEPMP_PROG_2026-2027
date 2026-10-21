#include <stdio.h>

int main(void)
{
    int n = 0, m = 0;
    const int BUF_SIZE = 100;
    int temp = 0;

    scanf("%d %d", &n, &m);

    int buf[BUF_SIZE] = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m && j < BUF_SIZE; j++)
        {
            scanf("%d", &temp);
            buf[j] += temp;
        }
    }

    for (int k = 0; k < m && k < BUF_SIZE; k++)
        printf("%d ", buf[k]);

    return 0;
}