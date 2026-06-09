#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[100];
int top;
void initstack()
{
    top=-1;
}//初始化堆栈 
int isempty()
{
    return top==-1;//为-1则返回值为1，不为-1则返回值为0
}//判断是否空栈 
int isfull()
{
    return top==99;
}//判断是否满栈 
void Error(char s[])
{
    printf("%s ",s);
    return;
} 
void push(int s[],int item)
{
    if(isfull())
    {
        Error("error");
    }
    else
    s[++top]=item;
}//入栈 
int pop(int s[])
{
    if(isempty())
    {
        Error("error");
    }
    else
    {
        return s[top--];
    }
} // @@ [missing return value when stack empty, leading to undefined behavior (garbage value printed)]
int main()
{
    int n,t;
    initstack();
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        if(n==1)
        {
            scanf("%d",&t);
            push(stack,t);
        }
        else if(n==0)
        {
            printf("%d ",pop(stack));
        }
    }
}