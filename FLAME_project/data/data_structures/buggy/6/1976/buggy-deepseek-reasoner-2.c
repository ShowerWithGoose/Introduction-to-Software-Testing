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
        printf("error "); // @@ This prints "error " but the function does not return a value, leading to undefined behavior; also main will still execute the subsequent printf, printing an incorrect value.
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
            pop(stack); // @@ This call ignores the return value of pop; the pop function may print "error " for an empty stack, but main will still proceed to the next line unconditionally.
            printf("%d ",stack[top+1]); // @@ After an empty pop, top remains -1, so stack[top+1] (stack[0]) prints the previous element, causing an extra number to appear in the output.
        }
        else
            break;
    }
    return 0;
}