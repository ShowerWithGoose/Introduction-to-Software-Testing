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
        printf("error "); // @@ Missing return statement for a non-void function, which causes a compilation error. It should return a status code to indicate failure.
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
            ans=pop(); // @@ Assigns the return value of pop() to ans, but pop() does not return a valid value on error, leading to undefined behavior.
            printf("%d ",ans); // @@ Prints the return value unconditionally. When a pop error occurs, it prints an invalid number instead of just "error ".
        }
        scanf("%d",&op);
    }
    
    return 0;
}