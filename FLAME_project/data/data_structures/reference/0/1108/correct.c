#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
   char s[300],a;
   gets(s);
   int i;
   int len=strlen(s);
   for(i=0;i<len;i++)
    {
       if(s[i]=='-')
       {
          if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<=s[i+1])
          {
             for(a=s[i-1]+1;a<s[i+1];a++)
             printf("%c",a);
          }
         else if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<=s[i+1])
          {
             for(a=s[i-1]+1;a<s[i+1];a++)
             printf("%c",a);
          }
         else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<=s[i+1])
          {
             for(a=s[i-1]+1;a<s[i+1];a++)
             printf("%c",a);
          }
         else printf("%c",s[i]);
       }
      else printf("%c",s[i]);
    }
     printf("\n");
     return 0;
}




