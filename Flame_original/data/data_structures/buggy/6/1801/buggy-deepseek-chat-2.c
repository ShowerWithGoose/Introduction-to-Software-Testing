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
    while(scanf("%d ",&op)&&op!=-1) // @@ The format string "%d " with a trailing space may cause issues with input parsing; the reference program uses "%d" without a space.
    {
        if(op==1) 
        {
            scanf("%d ",&num); // @@ The format string "%d " with a trailing space may cause issues with input parsing; the reference program uses "%d" without a space.
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ The return value of pop() is not printed; the reference program prints the popped value. Also, pop() does not return a value when the stack is empty, leading to undefined behavior.
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
    else return stack[top--]; // @@ When the stack is empty, the function does not return a value, which is undefined behavior. The reference program handles this by checking before calling pop().
}