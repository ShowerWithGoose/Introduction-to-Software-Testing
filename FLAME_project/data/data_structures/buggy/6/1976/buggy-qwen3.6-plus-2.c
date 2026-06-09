#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==99;
}
void push(int s[],int item)
{
    if(isfull())
        printf("error ");
    else
        s[++top]=item;
}
int pop(int s[])
{
    if(isempty())
        printf("error ");
    else
        return s[top--];
}
int main()
{
    int m,n;
    while(scanf("%d",&m)!=-1)
    {
        if(m==1)
        {
            scanf("%d",&n);
            push(stack,n);
        }
        else if(m==0)
        {
            if (isempty()) // @@ The original code calls pop() and prints regardless of whether the stack is empty, leading to incorrect output ("5" instead of "error") when popping from an empty stack. It should check isempty() first.
                printf("error ");
            else
                printf("%d ", pop(stack)); // @@ The original code manually accesses stack[top+1] after calling pop (which returns the value but the return value was ignored in the buggy logic flow or handled incorrectly). It should simply print the result of pop() or handle the printing correctly within the pop logic or here. Given the reference, printing the returned value of pop is the standard way.
        }
        else
            break;
    }
    return 0;
}