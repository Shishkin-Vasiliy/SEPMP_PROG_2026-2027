
#include <stdio.h>

union Data
{
    int a[4];
    char str[16];
};

int main()
{
    union Data data = {
        .a = {1819043144, 1461726319, 1684828783, 2593}
    };

    printf("%s\n", data.str);

    return 0;
}
