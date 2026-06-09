#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int empty(int []);
void push(int [],int);
void pop(int []);
int top=-1;
int main()
{
    int stack[100]={0},a[1000],flag,c,i=-1;
    while(scanf("%d",&c)!=EOF)
    {
        if(c==-1) break;
        else
        {
            a[++i]=c;
        }
    }
    a[++i]=-1;
    i=0;
    while(a[i]!=-1)
    {
        if(a[i]==1)
            push(stack,a[++i]);
        else if(a[i]==0)
            pop(stack);
        i++;
    }
}
int empty(int stack[])
{
    return (top==-1);
}
void push(int stack[],int x)
{
    if(top<99)
    {
        stack[++top]=x;
    }
    else if(top>=99)
        printf("error ");
}
void pop(int stack[])
{
    if(empty(stack))
    {
        printf("error ");
    }
    else if(!empty(stack))
    {
        printf("%d ",stack[top--]);
    }
}

