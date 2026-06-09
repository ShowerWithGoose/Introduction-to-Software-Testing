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
    if (isEmpty()) printf("error ");
    else return s[top--];
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
            printf("%d ",pop(s)); // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (since no return statement is executed in the if branch), which is then printed by printf as "%d ", leading to undefined behavior and incorrect output. The function should not print in pop() and should handle error printing consistently, or ensure a valid return in all paths.]
        }
    }
    
}