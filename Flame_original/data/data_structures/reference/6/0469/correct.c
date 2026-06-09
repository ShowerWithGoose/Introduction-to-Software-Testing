#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define M 100
int stack[M];
int top=-1;


int main()
{
    int x;
    int a;
    while(scanf("%d",&x)!=EOF)
    {
        if(x==1)
        {
            scanf("%d",&a);
            if(top==M-1)
                printf("error ");
            else
            {
                stack[++top]=a;
            }
        }
        else if(x==0)
        {
            if(top==-1)
                printf("error ");
            else
            {
                printf("%d ",stack[top]);
                top--;
            }
        }
        else if(x==-1)
            return 0;
    }
    return 0;
}

