#include <ctype.h>

void used_chars(const char *str, char *used)
{
    // индикаторный массив 
    // 1 если i-я буква алфавита встретилась, 0 в противном случае
    int indicator[26] = {0};

    for (const char *p = str; *p; p++) 
    {
        if (isalpha(*p)) 
        {
            int i = tolower(*p) - 'a';
            indicator[i] = 1;
        }
    }

    int k = 0;
    for (int i = 0; i < 26; i++) 
    {
        if (indicator[i])
            used[k++] = (char)('a' + i);
    }
    used[k] = '\0';
}