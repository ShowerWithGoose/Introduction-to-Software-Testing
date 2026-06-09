#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
    int m,n;
    int data[100];
    int top=0;
    while(scanf("%d",&n))
    {
        if(n==1)
        {
            scanf("%d",&m);
            if(top>100)
            {
                printf("error ");
            }
            else
            {
                data[top]=m;
                top++;
            }
        }
        else if(n==0)
        {
            if(top>=1)
            {
                printf("%d ",data[top-1]);
                top--;
            }
            else printf("error ");
        }
        else if(n==-1)
           return 0;

    }
    return 0;
}



