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
        Error("error"); // @@ [When the stack is empty, this function prints "error " but still proceeds to return an undefined value (since there's no return statement in the if block), leading to undefined behavior. The function must return a value in all paths because it's declared to return int.]
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
            printf("%d ",pop(stack)); // @@ [If pop() encounters an empty stack, it prints "error " but then returns an undefined/garbage value (due to missing return in the error case), which is then printed as "%d ", causing incorrect output like "error <garbage> " instead of just "error ".]
        }
    }
}