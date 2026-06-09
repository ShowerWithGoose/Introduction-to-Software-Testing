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
        printf("error "); // @@ [When the stack is empty, "error " is printed but the function still attempts to return a value, which is undefined behavior. Additionally, in main(), the return value of pop() is ignored, and instead stack[top+1] is printed unconditionally, which may access invalid memory.]
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
            pop(stack); // @@ [The pop() function may print "error ", but then main() always prints stack[top+1] regardless of whether pop succeeded or failed, leading to incorrect output or accessing invalid memory when the stack is empty.]
            printf("%d ",stack[top+1]); // @@ [This line assumes pop() succeeded and that stack[top+1] holds the popped value, but if pop() failed (stack empty), this accesses an invalid or stale location. Also, even if pop() succeeded, the value was already returned by pop(), but not used; instead, this re-accesses the stack after decrementing top, so stack[top+1] is correct only if pop() actually popped, but the logic is flawed because error case isn't handled here.]
        }
        else
            break;
    }
    return 0;
}