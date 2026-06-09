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
    else return s[top--]; // @@ The function is declared to return int, but when the stack is empty, it prints "error " and does not return a value, leading to undefined behavior. In the main function, printf("%d ",pop(s)) prints this undefined value (e.g., 6) after the error message.
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
            printf("%d ",pop(s)); // @@ When pop returns an undefined value on empty stack, this prints that garbage value (e.g., 6) after "error ", causing the wrong output "5 error 6 8 ..." instead of "5 error 8 ...".
        }
    }
    
}