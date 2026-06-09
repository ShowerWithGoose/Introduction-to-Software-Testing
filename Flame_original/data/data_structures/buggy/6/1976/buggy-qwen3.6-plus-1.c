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
        printf("error "); // @@ Compilation Error: The function 'pop' is declared to return an 'int', but this control path lacks a return statement, which causes a compilation failure in strict C compilers.
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
            pop(stack);
            printf("%d ",stack[top+1]); // @@ Logical Error: 'pop()' already decrements the global 'top' and returns the popped value. Ignoring the return value and accessing 'stack[top+1]' is incorrect and will print wrong values or execute even when the stack is empty. The return value of 'pop()' should be captured and printed instead.
        }
        else
            break;
    }
    return 0;
}