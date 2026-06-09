#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]); // @@ [Parameter name 'stcak' is misspelled; should be 'stack' to match usage and convention, though not a compilation error by itself, it's misleading. However, the real compilation issue is below.]
int isempty(int stack[]);
int isfull(int stack[]);
void push(int stack[],int item);
int pop(int stack[]);

int main()
{
    int op,num;
    initstack(stack);
    while(scanf("%d ",&op)&&op!=-1)
    {
        if(op==1) 
        {
            scanf("%d ",&num);
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ [The return value of pop() is ignored. When the stack is not empty, pop() returns the popped value, but main does not print it. This causes missing output for successful pops, leading to incorrect behavior (though not a compilation error). However, the actual compilation error is elsewhere.]
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
    if(isempty(stack)) printf("error ");
    else return stack[top--]; // @@ [Function pop() is declared to return int, but in the case of an empty stack, it prints "error " and then falls through without returning a value. This leads to undefined behavior and is a compilation warning/error in strict modes (missing return statement in all control paths).]
}