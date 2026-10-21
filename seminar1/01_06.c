#include <stdio.h>

int NumTransform(int n);

int main(void)
{
    int num = 0;
    int length = 0;
    int max = 0;
    
    scanf("%d", &num);
    
    while (num != 1)
    {
        printf("%d ", num);
        
        if (num > max)
            max = num;

        num = NumTransform(num);
        length++;
    }
    
    printf("\n");
    printf("Length = %d  ", length);
    printf("Max = %d\n", max);
}

int NumTransform(int n)
{
    if (n % 2 == 0)
        return n / 2;
    else 
        return 3 * n + 1;
}