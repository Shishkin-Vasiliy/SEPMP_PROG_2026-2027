#include <stdio.h>

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    
    if (num < 0 || num > 1000)
        printf("Ошибочное значение\n");

    else 
        printf("num + 1 = %d\n", num + 1);

    return 0;
}