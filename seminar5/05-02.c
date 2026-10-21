double *get_geometric_progression(double a, double b, int n)
{
    double *arr = (double *)calloc((size_t)n, sizeof(double));

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = a * power(b, i);
    }

    return arr;
}

double power(double b, int m)
{
    double res = 1;

    for (int i = 0; i < m; i++)
        res *= b;

    return res;
}