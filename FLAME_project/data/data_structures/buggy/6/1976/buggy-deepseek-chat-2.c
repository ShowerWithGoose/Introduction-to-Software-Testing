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
        printf("error "); // @@ This function prints "error " but does not return a value when empty, causing undefined behavior when the caller uses the return value.
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
            pop(stack); // @@ This calls pop() but ignores its return value; instead, it accesses stack[top+1] which is incorrect after a failed pop (when stack is empty, top remains -1, so stack[0] is accessed erroneously).
            printf("%d ",stack[top+1]); // @@ After a successful pop, top has been decremented, so stack[top+1] is the popped element, but this approach is fragile and duplicates the pop logic incorrectly. When pop fails (empty stack), this prints an unintended value.
        }
        else
            break;
    }
    return 0;
}