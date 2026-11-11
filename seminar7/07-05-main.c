int main()
{
    int n = 1000;
    double *array = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        array[i] = sin(M_PI * i / n);

    save_numbers_text("numbers.txt", array, n);
    save_numbers_binary("numbers.bin", array, n);

    free(array);

    return 0;
}