#include<stdio.h>
int top=-1;
int stack[200]={0};

int isEmpty(int s[])
{
    return top==-1;
}

int isFull(int s[])
{
    return top==199;
}

void push(int stack[],int item)
{
    if(isFull(stack))
        Error11("error"); // @@ The function Error11 prints "error " with a space, but the problem expects "error" without a space for push failure. Also, the function name is unconventional.
    else 
        stack[++top]=item;
}
void Error11(char s[])
{
    printf("%s ",s); // @@ This prints a space after the error message, but the problem requires "error" (no space) for push failure and "error " (with space) for pop failure. The space handling is inconsistent.
}
int pop(int s[])
{
    if(isEmpty(s))
        Error11("error"); // @@ The function Error11 prints "error " with a space, which is correct for pop failure, but the same function is used for push failure where no space is needed.
    else 
        return s[top--];
}
int main()
{
    int a,b,ans;
    while(~scanf("%d",&a))
    {
        if(a==-1)
        {
            break;
        }
        else if(a==1)
        {
            scanf("%d",&b);
            push(stack,b);
        }
        else if(a==0)
        {
            printf("%d ",ans=pop(stack)); // @@ When pop fails (stack empty), Error11 prints "error " but then this printf still executes, printing an uninitialized value (ans) after the error message, which is incorrect.
        }
    }
}