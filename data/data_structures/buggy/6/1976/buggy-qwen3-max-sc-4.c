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
            printf("%d ",stack[top+1]); @@ [When the stack is empty, pop() prints "error ", but then this line still tries to access stack[top+1], which is invalid. Also, when pop() succeeds, it returns the value but doesn't print it; instead, this line prints the value after decrementing top, but if pop() printed "error ", this line still prints garbage. The logic for printing popped values and errors is split incorrectly between pop() and main().]
        }
        else
            break;
    }
    return 0;
}