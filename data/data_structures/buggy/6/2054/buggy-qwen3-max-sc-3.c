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
        Error11("error"); // @@ [Error11 is not a standard function; should be replaced with proper output handling like printf]
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
        Error11("error"); // @@ [When stack is empty, pop should print "error " but currently returns undefined value which is then printed in main]
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
            printf("%d ",ans=pop(stack)); // @@ [If pop returns due to empty stack, it doesn't return a valid integer, leading to printing garbage or undefined behavior]
        }
    }
}