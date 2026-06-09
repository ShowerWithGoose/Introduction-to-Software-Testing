#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100

int s[MAXSIZE];
int top;

void initStack();
int isEmpty();
int isFull();
void push(int);
int pop();

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top==MAXSIZE-1)
        return 1;
    else
        return 0;
}

void initStack()
{
    top=-1;
}
void push(int a)
{
    if(isFull())
        printf("error ");
    else
    {
        top++;
        s[top]=a;
    }
}

int pop()
{
    if(isEmpty())
        printf("error ");
    else
    {
        top--;
        return s[top+1];
    }
}
int main()
{
    int op,x,ans;
    initStack();
    
    scanf("%d",&op);
    while(op!=-1)
    {
        if(op==1)
        {
            scanf("%d",&x);
            push(x);
        }
        else if(op==0)
        {
            ans=pop(); // @@ The pop function prints "error " directly to stdout when the stack is empty but does not return a valid value. The main function then unconditionally prints the return value of pop (which is undefined/garbage in the error case), resulting in extra incorrect output like "6" in the buggy output. The logic should handle the error state without printing a garbage number.
            printf("%d ",ans); // @@ This line executes even when pop() encountered an error and printed "error ". Since pop() returns an undefined value in the error case, this prints a garbage integer. It should only print the result if the pop was successful.
        }
        scanf("%d",&op);
    }
    
    return 0;
}