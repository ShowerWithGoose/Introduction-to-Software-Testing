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
        printf("error "); // @@ The function is declared to return int, but does not return a value when the stack is empty, causing undefined behavior.
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
            printf("%d ",stack[top+1]); // @@ After pop, top has been decremented, so stack[top+1] accesses the popped element, but if pop printed "error", this prints garbage or the wrong value.
        }
        else
            break;
    }
    return 0;
}