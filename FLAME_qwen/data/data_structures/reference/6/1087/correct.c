#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAXSIZE 100;
int top=-1;
int a[100];
int main()//1表示入栈操作,0表示出栈操作；-1表示操作结束。
{
    int n,m;
   
    while(~scanf("%d",&n))
    {
        if(n==1)
        {
           if(top>100)
           {
               printf("error ");
           }
           else{
               scanf("%d ",&m);
               top++;
               a[top]=m;
           }
            


        }
        else if(n==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",a[top]);
                top--;               

            }

        }
        else if(n==-1)
        {
            break;
        }
        
    }

    return 0;
}
