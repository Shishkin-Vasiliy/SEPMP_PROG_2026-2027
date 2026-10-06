#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *str, int k);

int main(void)
{
    int k;
    char str[200];
    
    scanf("%d ", &k);
    fgets(str, 200, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    encrypt(str, k);
    printf("%s\n", str);
    
    return 0;
}

void encrypt(char *str, int k)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper((unsigned char)str[i]))
            str[i] = 'A' + (((str[i] - 'A') + k) % 26 + 26) % 26;
        else if (islower((unsigned char)str[i]))
            str[i] = 'a' + (((str[i] - 'a') + k) % 26 + 26) % 26;
    }
}