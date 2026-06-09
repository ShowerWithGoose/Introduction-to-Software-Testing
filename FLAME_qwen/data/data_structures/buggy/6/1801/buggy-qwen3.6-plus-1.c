#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]);
int isempty(int stack[]);
int isfull(int stack[]);
void push(int stack[],int item);
int pop(int stack[]);

int main()
{
    int op,num;
    initstack(stack);
    while(scanf("%d ",&op)&&op!=-1) // @@ The trailing space in the format string causes scanf to consume whitespace and wait for non-whitespace input, which may block execution or fail to parse correctly. It should be "%d".
    {
        if(op==1) 
        {
            scanf("%d ",&num); // @@ The trailing space in the format string causes scanf to wait for non-whitespace input, potentially blocking execution. It should be "%d".
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ The return value of pop() is discarded, so the popped element is never printed as required by the problem. It should be printf("%d ", pop(stack)); or similar.
        }
    }
    
    return 0;
}

void initstack(int stack[])
{
    top=-1;
}

int isempty(int stack[])
{
    return top==-1;
}

int isfull(int stack[])
{
    return top==maxsize-1;
}

void push(int stack[],int item)
{
    if(isfull(stack)) printf("error ");
    else stack[++top]=item;
}

int pop(int stack[])
{
    if(isempty(stack)) printf("error "); // @@ When the stack is empty, this branch prints "error " but does not return an int value, leading to undefined behavior. It should return a value or handle output differently.
    else return stack[top--];
}