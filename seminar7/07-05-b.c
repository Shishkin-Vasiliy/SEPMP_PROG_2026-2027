
#include <stdio.h>
#include <stdint.h>

void save_numbers_binary(const char* filename, double* array, int n)
{
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
        return;

    uint32_t count = (uint32_t)n;

    fwrite(&count, 4, 1, file);
    fwrite(array, 8, n, file);

    fclose(file);
}
