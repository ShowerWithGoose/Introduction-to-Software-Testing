#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
//判断栈是否为空
int isfull()
{
    return top==MAXSIZE-1;
}
//判断栈是否为满
int isempty()
{
    return top==-1;
}
//入栈
void push(int n)
{
    if(isfull()) printf("error ");
    else
    {
        stack[++top]=n;
    }
}
//出栈
void pop()
{
    if(isempty()) printf("error ");
    else
    {
        printf("%d ",stack[top--]);
    }
}

int main()
{
    int num,op;
    while(scanf("%d",&op)!=-1)
    {
        if(op==0)
        {
            pop();
        }
        else if(op==1)
        {
            scanf("%d",&num);
            push(num);
        }
    }
    return 0;
}
