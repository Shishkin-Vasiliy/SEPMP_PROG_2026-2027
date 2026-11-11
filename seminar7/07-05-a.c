
#include <stdio.h>

void save_numbers_text(const char* filename, double* array, int n)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
        return;

    for (int i = 0; i < n; i++)
        fprintf(file, "%.15f\n", array[i]);

    fclose(file);
}
