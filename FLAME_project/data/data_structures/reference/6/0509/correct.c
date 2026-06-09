#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int main()
{
    int n;
    int top=-1;
    while(scanf("%d",&n)!=EOF)
    {
        if(1==n)
        {
            scanf("%d",&n);
            if(top==MAXSIZE-1)
                printf("error ");
            else
            {
                stack[++top]=n;
            }
        }
        if(0==n)
        {
            if(top==-1)
                printf("error ");
            else
            {
                printf("%d ",stack[top]);
                top--;
            }
        }
        if(-1==n)
        {
            break;
        }
    }
    return 0;
}

