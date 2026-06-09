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
        Error11("error"); // @@ [Error11 is not a standard function; likely intended to be a custom function but causes compilation error if not properly defined before use or if typo (should probably be a direct printf)]
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
        Error11("error"); // @@ [When stack is empty, pop should print "error ", but this call prints "error " correctly; however, the function returns an undefined value which is used in main()]
    else 
        return s[top--]; // @@ [This returns the popped value but does not print it; printing is done in main(), but if pop fails (empty), it still returns garbage which is printed in main()]
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
            printf("%d ",ans=pop(stack)); // @@ [If pop() encounters an empty stack, it calls Error11("error") which prints "error ", but then returns an undefined value (since no return in if branch), leading to printing garbage after "error ". Also, even when error is printed inside pop, main still prints the return value, causing double output or incorrect format.]
        }
    }
}