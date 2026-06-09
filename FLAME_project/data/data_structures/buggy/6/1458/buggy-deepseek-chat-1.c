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
            ans=pop();
            printf("%d ",ans); // @@ [Error: When pop() returns due to empty stack, it does not return a value, so ans is uninitialized and prints garbage (6 in this case). The function should not print the value when the stack is empty.]
        }
        scanf("%d",&op);
    }
    
    return 0;
}