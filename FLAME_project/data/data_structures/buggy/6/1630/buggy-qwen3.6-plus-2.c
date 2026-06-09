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
            if (isEmpty()) printf("error "); // @@ The original code calls pop(s) which prints "error " internally but then also prints the return value (undefined/garbage or 0) because printf("%d ", pop(s)) always executes. When stack is empty, pop prints "error " but doesn't return a valid value to be printed by the outer printf. We need to handle the error case here before printing, or change the structure. The reference implementation handles printing inside pop. Here, pop returns int. If empty, it prints "error " but returns nothing (undefined behavior). The main function then prints that undefined return value. We should check isEmpty first.
            else printf("%d ", pop(s));
        }
    }
    
}