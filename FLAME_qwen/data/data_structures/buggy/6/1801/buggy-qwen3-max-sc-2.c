#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]); // @@ [Parameter name 'stcak' is misspelled; should be 'stack' to match usage and intent, though not directly causing compilation error, it's inconsistent. However, the real compilation issue is missing return statement in non-void function 'pop' when stack is empty.]
int isempty(int stack[]);
int isfull(int stack[]);
void push(int stack[],int item);
int pop(int stack[]); // @@ [Function 'pop' is declared to return int, but when stack is empty, it prints "error " and falls through without returning a value, which causes undefined behavior and may lead to compilation warning/error depending on compiler settings.]

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
            pop(stack); // @@ [Return value of 'pop' is ignored. When pop succeeds, it returns the popped value, but main does not print it. Also, when pop fails (empty), it prints "error ", but successful pops are not printed at all, violating output requirement.]
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
    if(isempty(stack)) printf("error "); // @@ [When stack is empty, this prints "error ", but then the function continues and reaches end without returning an int, which is invalid for a non-void function and causes undefined behavior / compilation error.]
    else return stack[top--];
} // @@ [Missing return statement after printing "error ". Should either return a dummy value (though logically flawed) or restructure. But more critically, the main function never prints the popped value on success.]