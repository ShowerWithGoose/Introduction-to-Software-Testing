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
    while(scanf("%d ",&op)&&op!=-1) // @@ The trailing space in the scanf format string causes it to consume all trailing whitespace and wait for non-whitespace input, leading to incorrect parsing or program hanging. Additionally, op may be used uninitialized if scanf fails.
    {
        if(op==1) 
        {
            scanf("%d ",&num); // @@ The trailing space in the scanf format string causes input parsing issues and may cause the program to hang waiting for further input.
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ The return value of pop() is discarded, so the popped elements are not printed to the output as required by the problem description.
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
    if(isempty(stack)) printf("error "); // @@ Missing return statement for a non-void function when the stack is empty, which causes undefined behavior and compilation errors/warnings.
    else return stack[top--];
}