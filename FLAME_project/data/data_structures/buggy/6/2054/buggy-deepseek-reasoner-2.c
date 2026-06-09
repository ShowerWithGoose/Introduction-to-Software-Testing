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
        Error11("error");
    else 
        stack[++top]=item;
}
void Error11(char s[])
{
    printf("%s ",s);
}
int pop(int s[]) // @@ [Function returns int but when stack is empty, no return value is provided, leading to undefined behavior and printing garbage]
{
    if(isEmpty(s))
        Error11("error"); // @@ [After printing the error message, the function does not return a value; execution falls off without returning, causing undefined behavior]
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
            printf("%d ",ans=pop(stack)); // @@ [This line always prints the return value of pop, but when pop is called on an empty stack, the value is undefined; should only print when the pop actually occurred]
        }
    }
}