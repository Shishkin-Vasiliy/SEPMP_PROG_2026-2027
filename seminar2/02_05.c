void print_binary(int n)
{
    if (n > 1)
        print_binary(n / 2);
    printf("%d", n % 2);
}