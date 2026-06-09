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
int pop(int s[]) // @@ The pop function should be of type void, not int. When the stack is empty, it prints "error " but does not return a value, causing undefined behavior when the caller uses the return value (e.g., printing a garbage integer).
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
            printf("%d ",pop(s)); // @@ This line uses the return value of pop(s). When pop prints "error " (empty stack), it returns a garbage integer, resulting in an extra unwanted number in the output. The correct approach is to have pop itself handle both printing and error output without returning a value.
        }
    }
    
}