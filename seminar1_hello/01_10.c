#include <stdio.h>
#define ARR_SIZE 1000

int main(void)
{
    int Arr[ARR_SIZE] = {};
    int k = 0;
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &(Arr[i]));

    for (int i = 0; i < n; i++)
    {
        if (Arr[i] >= 0)
        {
            Arr[k] = Arr[i];
            k++;
        }
    }
    
    n = k;

    for (int i = 0; i < n; i++)
        printf("%d ", Arr[i]);

    return 0;
}