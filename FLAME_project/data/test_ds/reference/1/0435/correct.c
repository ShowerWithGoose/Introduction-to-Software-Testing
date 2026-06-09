#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
     int i;
     char s[200];
     gets(s);
     for(i = 0;s[i]!='\0';i++)
     {
         if(s[i]=='-')
         {
             if((isupper(s[i+1])>0&&isupper(s[i-1])>0)||(islower(s[i+1])>0&&islower(s[i-1])>0)||(isdigit(s[i+1])>0&&isdigit(s[i-1])>0))
              {
                  if((int)(s[i-1])>=(int)(s[i+1]))
                  {
                      printf("%c",s[i]);
                      continue;
                  }
                  for(int k = (int)(s[i-1])+1;k<(int)(s[i+1]);k++)
                  {
                      printf("%c",k);
                  }

              }
              else
              {
                  printf("%c",s[i]);
              }
         }
         else
         {
             printf("%c",s[i]);
         }
     }


     return 0;
}



