#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n = 0;
    int max = INT_MIN;
    int max_count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &i);

        if (i > max)
        {
            max = i;
            max_count = 1;
        }

        else if (i == max)
            max_count++;
    }
    printf("MAX = %d\n", max);
    printf("MAX_COUNT = %d\n", max_count);

    return 0;
}