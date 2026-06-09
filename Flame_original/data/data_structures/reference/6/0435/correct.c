#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
     char s[300],num[10];
     int z[100],way,n,i,top = -1,k;
     gets(s);
     while(s[i]!='-'&&s[i+1]!='1')
     {
         k = 0;
         if(s[i] == '1')
         {
             i+=2;
             for(k = 0;s[i+k]!=' ';k++)
             {
                 num[k] = s[i+k];
             }
             num[k]='\0';
             n = atoi(num);
             top++;
             if(top<100)
             {
                 z[top] = n;
             }
             else
             {
                 printf("error ");
             }
         }
           else if(s[i] == '0')
         {
             if(top>=0)
             {
                 printf("%d ",z[top]);
                 top--;
             }
             else
             {
                 printf("error ");
             }
             k = 1;
         }
         i = i+k+1;
     }
     return 0;
}

