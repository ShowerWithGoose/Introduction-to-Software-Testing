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
        Error("error"); // @@ [Error function prints "error " but does not return a value; the function is declared to return int, so this path leads to undefined behavior. Also, when pop is called on an empty stack, the program should print "error " and continue, but here it prints "error " and then returns nothing, causing the caller to print an undefined value. The correct behavior is to print "error " and not print any popped value.]
    }
    else
    {
        return s[top--];
    }
}
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
            printf("%d ",pop(stack)); // @@ [When pop returns due to empty stack, it does not return a valid value, so this prints an undefined integer. The expected output for an empty pop is just "error " without a number. The program should check for empty stack before calling pop, or modify pop to handle the error without returning a value.]
        }
    }
}