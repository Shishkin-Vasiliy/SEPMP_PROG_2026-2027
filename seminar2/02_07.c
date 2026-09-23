#include <stdio.h>

int count_even(int arr[], size_t size);

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    int evens = count_even(numbers, size);

    printf("evens = %d\n", evens);

    return 0;
}

int count_even(int arr[], size_t size) 
{
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            count++;
    }

    return count;
}