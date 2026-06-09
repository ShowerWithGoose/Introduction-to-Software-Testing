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
}@@ // The function does not return a value in the error case (when stack is empty), leading to undefined behavior when the caller uses the return value.

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
            ans=pop();@@ // When pop() prints "error ", it does not return a valid integer, so 'ans' has an undefined value which is then printed.
            printf("%d ",ans);
        }
        scanf("%d",&op);
    }
    
    return 0;
}