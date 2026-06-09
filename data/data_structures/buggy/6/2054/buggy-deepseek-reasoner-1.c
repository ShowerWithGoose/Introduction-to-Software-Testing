#include<stdio.h>
int top=-1;
int stack[200]={0}; // @@ stack size should be 100 (MAXSIZE=100), not 200
int isEmpty(int s[])
{
    return top==-1;
}
int isFull(int s[])
{
    return top==199; // @@ should be top==99 for stack size 100
}
void push(int stack[],int item)
{
    if(isFull(stack))
        Error11("error"); // @@ prints "error " (with space), but reference prints "error" without space; also should not push after error (already correct)
    else 
        stack[++top]=item;
}
void Error11(char s[])
{
    printf("%s ",s);
}
int pop(int s[])
{
    if(isEmpty(s))
        Error11("error"); // @@ missing return value; when error, function should not return anything, but caller later uses the returned value
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
            printf("%d ",ans=pop(stack)); // @@ prints an extra integer when pop fails (due to missing return in pop on error)
        }
    }
}