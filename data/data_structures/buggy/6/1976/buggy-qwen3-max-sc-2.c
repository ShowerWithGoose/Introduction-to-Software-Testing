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
        printf("error "); // @@ [When the stack is empty, this prints "error ", but then the function returns an undefined value (no return statement for this path), which leads to undefined behavior when the caller tries to use the return value.]
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
            pop(stack); // @@ [The pop function may return a value only when the stack is not empty, but when it's empty, it prints "error " and falls through without returning a value. However, the bigger issue is that the program then unconditionally prints `stack[top+1]` regardless of whether the pop succeeded or failed. If the stack was empty, `top` is -1, so `stack[top+1]` is `stack[0]`, which is invalid and leads to incorrect output. Also, even if pop succeeded, the value printed here is from the stack after decrementing `top`, so `stack[top+1]` is actually the popped value—but this logic fails in the error case.]
            printf("%d ",stack[top+1]); // @@ [This line always executes after pop(), even when pop() printed "error ". It should only print the popped value if the pop was successful. In the error case, it prints garbage or wrong data instead of suppressing this print. Moreover, if pop() printed "error ", we shouldn't print a number afterward. This causes incorrect output format.]
        }
        else
            break;
    }
    return 0;
}