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
            pop(stack); @@ // The pop function returns the popped value, but this line ignores the return value and instead prints stack[top+1], which may be invalid (e.g., after an "error" case or when stack is empty). Also, if pop() prints "error ", then printing stack[top+1] afterward leads to incorrect output.
            printf("%d ",stack[top+1]); @@ // This accesses stack[top+1] even when pop failed (i.e., stack was empty), causing undefined behavior or wrong output. Additionally, if pop succeeded, the value was already available as the return value of pop(), so this double-prints or misprints.
        }
        else
            break;
    }
    return 0;
}