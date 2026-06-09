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
    else return s[top--]; // @@ [The function returns an int, but when the stack is empty, it prints "error " and does not return a value, leading to undefined behavior. Additionally, the caller always prints the return value, so when empty, it prints garbage after "error ". The pop function should handle the empty case by returning a sentinel value or printing inside and not returning, but the caller's printf("%d ",pop(s)) will still execute and print an undefined value.]
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
            printf("%d ",pop(s)); // @@ [When pop(s) returns without a value due to empty stack, this prints an undefined integer after "error ", which does not match the expected output format. The expected output should only print "error " without an extra number.]
        }
    }
    
}