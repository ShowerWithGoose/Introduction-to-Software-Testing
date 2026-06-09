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
    if (isEmpty()) printf("error "); @@ [When the stack is empty, this function prints "error " but still returns an undefined value (since no return statement is executed in that branch). The calling code then prints this undefined return value as "%d ", leading to garbage output like "6" in the buggy output.]
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
            printf("%d ",pop(s)); @@ [This line always tries to print the return value of pop(), even when pop() printed "error ". When pop() encounters an empty stack, it prints "error " but does not return a valid integer, causing undefined behavior and printing garbage (e.g., "6").]
        }
    }
    
}