#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 105

int sta[105];
int top;

int main()
{
    int op;
    while(scanf("%d",&op),op!=-1)
    {
        if(op==1)
        {
            top++;
            if(top>100)
            {
                printf("error ");
                top--;
                continue;
            }
            scanf("%d",&sta[top]);
            continue;
        }
        if(op==0)
        {
            if(top==0)
            {
                printf("error ");
                continue;
            }
            printf("%d ",sta[top]);
            top--;
            continue;
        }
    }
    return 0;
}

