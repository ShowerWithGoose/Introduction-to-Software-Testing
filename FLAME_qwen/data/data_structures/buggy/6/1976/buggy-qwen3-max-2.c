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
        printf("error "); // @@ [When the stack is empty, this prints "error ", but then the function returns an undefined value (since no return statement follows). This leads to undefined behavior when the caller tries to use the return value.]
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
            pop(stack); // @@ [The pop function may return a value or not depending on whether the stack is empty. However, in the empty case, it prints "error " but still falls through without returning a value, causing undefined behavior. Additionally, the next line unconditionally prints stack[top+1], which is invalid if the pop failed (i.e., stack was empty) or even if it succeeded because top has already been decremented.]
            printf("%d ",stack[top+1]); // @@ [This line always tries to print stack[top+1], but if the pop operation resulted in an "error" (i.e., stack was empty), then top is still -1, so stack[0] is printed regardless — which is incorrect. Also, if pop succeeded, stack[top+1] is the popped value, but this duplicates output: the reference program prints inside pop(), whereas here pop() doesn't print the value on success, so this line attempts to compensate, but fails in error cases.]
        }
        else
            break;
    }
    return 0;
}