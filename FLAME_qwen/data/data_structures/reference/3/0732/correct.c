#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main()
{
    char str[105]={};
    scanf("%s",str);
    int pinf=0;
    int pind=0;
    int cnt;
   while(str[pinf]=='0'||str[pinf]=='.')
   {
       pinf++;
   }
   while(str[pind]!='.')
       pind++;
   if(pinf<pind)
   {
       cnt=pind-pinf-1;
   }
   else
   {
       cnt=pind-pinf;
   }
   if(cnt>=0)
   {
       int i=1;
       printf("%c",str[0]);
       printf(".");
       while (str[i]!='\0')
       {
           if(str[i]=='.')
           {
               i++;
               continue;
           } else{
               printf("%c",str[i]);
               i++;
           }

       }
       printf("e%d",cnt);
   }
   else
   {
       printf("%c",str[pinf]);
       if(str[pinf+1]!='\0')
            printf(".");
       int i=pinf+1;
       while (str[i]!='\0')
       {
           printf("%c",str[i]);
           i++;
       }
       printf("e%d",cnt);
   }

    return  0;
}

