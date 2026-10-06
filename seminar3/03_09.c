#include <stdio.h>
#include <ctype.h>

void trim_after_first_space(char *s);

int main(void)
{
    char a[] = "Cats and dogs";
    printf("a     = <%s>\n", a);
    trim_after_first_space(a);
    printf("a_new = <%s>\n", a);

    return 0;
}

void trim_after_first_space(char *s)
{
    int i = 0;
    for (; s[i] != '\0' && !isspace(s[i]); i++)
        ;
    if (isspace(s[i]))
        s[i] = '\0';
}