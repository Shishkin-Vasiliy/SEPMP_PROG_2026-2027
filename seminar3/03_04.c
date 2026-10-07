#include <stdio.h>
#include <string.h>

#define MAX_LINE 100

int main(void)
{
   char s1[MAX_LINE] = {0};
   char s2[MAX_LINE] = {0};

   scanf("%s", s1);
   scanf("%s", s2);

   size_t len1 = strlen(s1);
   size_t len2 = strlen(s2);
 
   for (size_t i = 0; i < len1 || i < len2; i++)
   {
      if (i < len1 && s1[i])
         printf("%c", s1[i]);
      if (i < len2 && s2[i])
         printf("%c", s2[i]);
   }
   printf("\n");

   return 0;
}