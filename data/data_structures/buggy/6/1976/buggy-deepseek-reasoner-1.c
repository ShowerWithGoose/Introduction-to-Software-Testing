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
} // @@ [Missing return value: when the stack is empty, the function prints "error " but does not return an integer, causing undefined behavior and a compilation error (control reaches end of non-void function).]
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
            printf("%d ",stack[top+1]);
        }
        else
            break;
    }
    return 0;
}