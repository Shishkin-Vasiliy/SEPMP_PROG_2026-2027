#include <stdio.h>

int main(void)
{
    int num = 0;

    scanf("%d", &num);

    if (num % 2 == 0 && ((num <= 20 && num >= 0) || (num < 200 && num > 100)))
        printf("Yes\n");
    else 
        printf("No\n");

    return 0;
}