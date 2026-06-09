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
int pop(int s[]) @@ // Missing return statement when stack is empty; function declared to return int but does not return a value on error path.
{
    if(isempty())
        printf("error "); @@ // After printing "error ", function should return a dummy value (e.g., return 0) to avoid undefined behavior.
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
            printf("%d ",stack[top+1]); @@ // This line prints even when pop() on empty stack outputs "error ", causing spurious output. The program should not print a number after an error pop.
        }
        else
            break;
    }
    return 0;
}