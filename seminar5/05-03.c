char *concat(const char *a, const char *b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    char *res = calloc(len_a + len_b + 1, sizeof(char));

    strcpy(res, a);
    strcat(res, b);

    return res;
}