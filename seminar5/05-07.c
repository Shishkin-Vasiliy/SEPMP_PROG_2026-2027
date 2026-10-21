size_t count_if(int *a, size_t n, int (*predicat)(int))
{
    size_t res = 0;
    for (size_t i = 0; i < n; i++)
    {  
        res += predicat(a[i]);
    }
    return res;
}

int is_negative(int num)
{
    if (num < 0)
        return 1;
    else 
        return 0;
}

int is_even(int num)
{
    if (num % 2 == 0)
        return 1;
    else    
        return 0;
}

int is_square(int num)
{
    if (num < 0)
        return 0;

    int temp = (int)(sqrt(num));

    if (temp * temp == num)
        return 1;
    else
        return 0;
}