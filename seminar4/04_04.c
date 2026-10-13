void mult2(int *p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        p[i] *= 2;
}

void mult2(int *p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        *(p + i) *= 2;
}