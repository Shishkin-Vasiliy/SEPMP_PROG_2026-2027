
#include <stdio.h>
#include <string.h>

int main()
{
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};
    char str[16];

    memcpy(str, a, sizeof(a));

    printf("%s\n", str);

    return 0;
}
