#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct stack
 {
     int top;
     int date[1000];
 };
 int main()
 {
     struct stack a;
     a.top=0;
     int n,i,b;
     while(scanf("%d",&n)!=EOF)
     {
         if(n==1)
         {
             if(a.top>99)
                printf("error ");
             else
             {   scanf("%d",&b);
                 a.date[a.top]=b;
                 a.top++;
             }
         }
         else if(n==0)
         {
             if(a.top<1)
                printf("error ");
             else
             {
                 printf("%d ",a.date[a.top-1]);
                 a.top--;
             }
         }
         else if(n==-1)
            break;
     }
     return 0;
 }

