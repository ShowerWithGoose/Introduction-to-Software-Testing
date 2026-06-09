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
        Error11("error"); // @@ [Error11 is not a standard function; this will cause a compilation error because Error11 is used before being declared (though it is defined later, in C this may still be allowed depending on compiler, but more critically, the logic of printing "error" should happen here and the program should likely continue or handle state, but the real issue is in pop()]
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
        Error11("error"); // @@ [When the stack is empty, this prints "error ", but then the function returns an undefined value (no return statement in this branch). The calling code in main() always prints the return value of pop(), which leads to undefined behavior when popping from empty stack. This causes incorrect output or runtime issues, but more pressingly, the missing return in this branch may cause compilation warnings or errors in strict modes. However, the primary bug is that main() unconditionally prints the result of pop(), even when it returns nothing valid.]
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
            printf("%d ",ans=pop(stack)); // @@ [This line always prints the return value of pop(). However, when the stack is empty, pop() calls Error11("error") but does not return a value, leading to undefined behavior. Moreover, even if pop() returned a dummy value, the code would print both "error " (from inside pop) and then an invalid number (from this printf), which is wrong. The correct behavior is to only print "error " and not print any number in that case.]
        }
    }
}