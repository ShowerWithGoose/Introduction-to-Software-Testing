#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[100];
int top=-1;
void push(int n)
{
    if(top==99)
        printf("error ");
    else
        stack[++top]=n;
}
void pop()
{
    if(top==-1)
        printf("error ");
    else
        printf("%d ",stack[top--]);
}
int main()
{
    int m,n;
    while(1)
    {
        scanf("%d",&m);
        if(m==1)
        {
            scanf("%d",&n);
            push(n);
        }
        else if(m==0)
            pop();
        else break;
    }
    return 0;
}

