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
            if(isempty()) // @@ The original code did not check if the stack is empty before popping, leading to incorrect behavior and output when popping from an empty stack. It should print "error " if empty.
                printf("error ");
            else
                printf("%d ", pop(stack)); // @@ The original code called pop but didn't use its return value correctly, instead accessing stack[top+1] which is logically flawed and doesn't handle the empty case properly. It should print the returned value from pop.
        }
        else
            break;
    }
    return 0;
}