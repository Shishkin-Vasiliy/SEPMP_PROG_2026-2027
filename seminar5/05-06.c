void sort(int *a, size_t n, int (*Compare)(int a, int b))
{
    for (size_t j = 0; j < n; j++)
    {
        size_t min_index = j;
        for (size_t i = j + 1; i < n; i++)
        {
            if (Compare(a[i], a[min_index]) < 0)
                min_index = i;
        }

        int temp = a[j];
        a[j] = a[min_index];
        a[min_index] = temp;
    }
} 