#include <stdio.h>
#include <string.h>

int main(void)
{
   char *s1;
   char *s2;

   scanf("%s", s1);
   scanf("%s", s2);

   int len1 = strlen(s1);
   int len2 = strlen(s2);
 
   for (int i = 0; i < len1 || i < len2; i++)
   {
      if (i < len1 && s1[i])
         printf("%c", s1[i]);
      if (i < len2 && s2[i])
         printf("%c", s2[i]);
   }
   printf("\n");

   return 0;
}