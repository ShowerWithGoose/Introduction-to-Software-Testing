#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXSIZE 100
int Stack[MAXSIZE];
int top;
void initStack()//初始化堆栈
{
    top=-1;
}
int isEmpty()//判断堆栈是否为空，栈空，返回1，否则，返回0
{
    return top==-1;
}
int isFull()//判断堆栈是否为满，栈满。返回1，否则，返回0
{
    return top==MAXSIZE-1;
}
void push(int Stack[],int elem)//进栈
{
    if(isFull())
        printf("error ");
    else
        Stack[++top]=elem;
}
void pop(int Stack[])//出栈
{
    if(isEmpty())
        printf("error ");
    else
        printf("%d ",Stack[top--]);
}
int main()
{
    int judge[200];
    int n,i=0,j;
    initStack();
    scanf("%d",&n);
    while(n!=-1)
    {
        judge[i++]=n;
        scanf("%d",&n);
    }
    for(j=0;j<i;j++)
    {
        if(judge[j]==1)
            push(Stack,judge[j+1]);
        else if(judge[j]==0)
            pop(Stack);
        else
            continue;
    }
    
    return 0;
}
