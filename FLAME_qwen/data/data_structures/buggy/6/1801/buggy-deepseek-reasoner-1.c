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
    while(scanf("%d ",&op)&&op!=-1)
    {
        if(op==1) 
        {
            scanf("%d ",&num);
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ [The return value of pop (the popped element) is not printed. According to the problem, each successful pop must output the popped value followed by a space. Should be: printf("%d ", pop(stack));]
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
    if(isempty(stack)) printf("error "); // @@ [When stack is empty, the function prints "error " but does not return a value. This causes undefined behavior because the function is declared to return int. Should have a return statement (e.g., return 0) to avoid undefined behavior, although the returned value on error is unused.]
    else return stack[top--]; // @@ [The popped value is returned, but main does not use it. However, if main is fixed to print the return value, this line would be correct. The error is in main's call.]
}