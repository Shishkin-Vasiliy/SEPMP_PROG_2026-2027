char* strmax(char** strings, size_t n)
{
    if (n == 0)
        return NULL;

    char* max = strings[0];

    for (size_t i = 1; i < n; i++) {
        if (strcmp(strings[i], max) > 0)
            max = strings[i];
    }

    return max;
}