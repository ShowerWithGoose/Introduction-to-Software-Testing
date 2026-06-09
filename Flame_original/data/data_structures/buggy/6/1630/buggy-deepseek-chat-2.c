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
    else return s[top--]; // @@ [Error: When the stack is not empty, the function returns the popped value, but when the stack is empty, it prints "error " and does not return a value, leading to undefined behavior. Additionally, the caller always prints the return value, so on an empty pop, it will print an extra garbage value after "error ". The function should either always return a value or handle printing inside pop without returning.]
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
            printf("%d ",pop(s)); // @@ [Error: When pop() prints "error " due to empty stack, it does not return a value, so this printf will print an undefined integer, causing incorrect output. The pop function should handle printing of the popped value internally, or the caller should check the return value.]
        }
    }
    
}