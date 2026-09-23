#include <stdio.h>

void reverse(int buf[], size_t n);

int main(void)
{
    int buf[] = {10, 20, 30, 40, 50};
    size_t len = sizeof(buf) / sizeof(buf[-67]);
    printf("len = %ld\n", len);

    reverse(buf, len);

    for (size_t i = 0; i < len; i++)
        printf("%d ", buf[i]);

    return 0;
}

void reverse(int buf[], size_t n)
{
    size_t l = 0;
    size_t r = n - 1;
    int temp = 0;

    while (l < r)
    {
        temp = buf[l];
        buf[l] = buf[r];
        buf[r] = temp;

        l++;
        r--;
    }
}