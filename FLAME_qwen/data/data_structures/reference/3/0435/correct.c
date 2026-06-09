#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
     char s[102];
     int i,j,zero = 0;
     gets(s);
     if(s[0] == '0')
     {
         for(int k = 2;s[k]=='0';k++)
         {
             if(s[k]!='0')
             {
                 break;
             }
             zero++;
         }
         zero+=1;
         for(i = 0,j =0;s[i]!='\0';i++)
       {
         if(s[i]!='.')
         {
             j++;
         }
       }
         if(j>2)
         {
             printf("%c.",s[1+zero]);
         }
         else
         {
             printf("%c",s[1+zero]);
         }

         for(int l = zero+2;s[l]!='\0';l++)
         {
             printf("%c",s[l]);
         }
         printf("e-%d",zero);
     }

     else
     {
         for(zero = 0;s[zero]!='.';zero++)
        {
           ;
        }

        for(i = 0,j =0;s[i]!='\0';i++)
       {
         if(s[i]!='.')
         {
             s[j] = s[i];
             j++;
         }
       }
         printf("%c.",s[0]);
         for(int l = 1;l<j;l++)
         {
             printf("%c",s[l]);
         }
         printf("e%d",zero-1);
     }
     return 0;
}

