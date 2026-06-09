#include<stdio.h>
int top=-1;
int stack[200]={0}; // @@ Array size should be 100 to match the maximum capacity specified in the problem.

int isEmpty(int s[])
{
    return top==-1;
}

int isFull(int s[])
{
    return top==199; // @@ Should check top==99 for a stack with maximum capacity of 100.
}

void push(int stack[],int item)
{
    if(isFull(stack))
        Error11("error"); // @@ Function 'Error11' is called before it is declared, causing a compilation error.
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
        Error11("error"); // @@ The 'pop' function does not return a value in this branch, leading to undefined behavior or compilation error.
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
            printf("%d ",ans=pop(stack)); // @@ If 'pop' fails, it prints "error " but does not return a value, causing garbage to be printed; also, the problem requires only "error " on failure.
        }
    }
}