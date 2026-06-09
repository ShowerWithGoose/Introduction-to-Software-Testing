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
        Error("error"); // @@ The function prints "error " but does not stop execution or indicate failure to the caller. The caller in main() still proceeds to print the return value of pop(), which is undefined/garbage when the stack is empty, leading to incorrect output like '6' instead of just 'error '. The logic should handle the error state such that no extra number is printed.
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
            printf("%d ",pop(stack)); // @@ This line blindly prints the result of pop(). If pop() encounters an empty stack, it calls Error() which prints "error ", but then returns an undefined value (since there's no return in the if branch, though strictly speaking in C this is undefined behavior for a non-void function). Even if it returned something, printing it results in "error <garbage> ". The correct behavior is to print "error " ONLY. The pop function should probably return a status or the main loop should check for emptiness before popping.
        }
    }
}