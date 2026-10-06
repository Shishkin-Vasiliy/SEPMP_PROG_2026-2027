#include <stdio.h>
#include <string.h>

int is_palindrome(char *s);
int main(void)
{
    char *s;

    scanf("%s", s);

    int res = is_palindrome(s);
    printf("res = %d\n", res);

    if (!res)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

int is_palindrome(char *s)
{
    int len = strlen(s);
    int res = 0;

    int l = 0;
    int r = len - 1;

    while (l < r)
    {
        res += s[l] - s[r];
        l++;
        r--;
    }
    if (res >= 0)
        return res;
    else
        return -res;
}
