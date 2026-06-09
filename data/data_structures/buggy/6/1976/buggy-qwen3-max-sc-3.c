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
        printf("error "); // @@ [When the stack is empty, this prints "error ", but then the function returns an undefined value (since no return statement follows). The calling code in main() will still try to use the returned value, leading to undefined behavior.]
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
            pop(stack); // @@ [The pop function may not return a valid value when the stack is empty (it falls off without returning), and even when it does return a value, the main function ignores it and instead prints stack[top+1], which is incorrect because top has already been decremented in pop(). Also, if pop() printed "error ", printing stack[top+1] afterward adds extra incorrect output.]
            printf("%d ",stack[top+1]); // @@ [This line incorrectly assumes that a pop operation succeeded and tries to print the popped value by accessing stack[top+1]. However, if the stack was empty, "error " was already printed, and this prints garbage or causes undefined behavior. If the pop succeeded, the value was already available from the return of pop(), but the design mixes two approaches: printing inside pop() and also here. This leads to either double output or wrong output.]
        }
        else
            break;
    }
    return 0;
}