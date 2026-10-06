#include <stdio.h>
#include <string.h>

void safe_strcpy(char *dest, size_t n, const char *src);

int main(void)
{
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    
    safe_strcpy(a, 10, b);
    printf("a = %s\n", a);
    
    return 0;
}

void safe_strcpy(char *dest, size_t n, const char *src)
{
    size_t i = 0;

    while (i < n - 1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}