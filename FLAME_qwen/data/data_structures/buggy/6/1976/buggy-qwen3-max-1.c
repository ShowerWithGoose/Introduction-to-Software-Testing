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
            pop(stack);
            printf("%d ",stack[top+1]); @@ [When the stack is empty, pop() prints "error " but does not return a value; then accessing stack[top+1] leads to undefined behavior. Also, even when pop succeeds, the popped value should be printed inside pop(), not after calling pop() using stack[top+1], because top has already been decremented in pop(). This causes incorrect output or reading from invalid memory.]
        }
        else
            break;
    }
    return 0;
}