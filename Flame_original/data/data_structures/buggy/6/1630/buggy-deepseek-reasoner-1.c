#include<stdio.h>
#include<string.h>
#define MAXSIZE 100 //栈的最大长度
int s[MAXSIZE];//栈，使用数组存储
int top = -1;
int isFull()
{
    return top == MAXSIZE - 1;
}
int isEmpty()
{
    return top == -1;
}
void initStack()
{
    top = -1;
}
void push(int s[], int item)
{
    if(isFull()) printf("error ");
    else s[++top] = item;
}
int pop(int s[])
{
    if (isEmpty()) printf("error "); // @@ [Missing return value when stack is empty; function has undefined behavior and main will print garbage]
    else return s[top--]; // @@ [This return only covers non-empty case; but the design of printing in main is inconsistent with error handling]
}
int main()
{
    int n,x;
    initStack();
    while(scanf("%d",&n)!=EOF )
    {
        if(n==-1) break;
        
        if(n==1)
        {
            scanf("%d",&x);
            push(s,x);
        }
        else if(n==0)
        {
            printf("%d ",pop(s)); // @@ [Always prints return value, even when pop outputs "error" and returns undefined value; should only print when pop succeeds]
        }
    }
    
}