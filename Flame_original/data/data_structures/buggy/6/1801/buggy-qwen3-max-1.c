#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]); // @@ [Parameter name 'stcak' is misspelled; should be 'stack' for consistency, though not a compilation error by itself, but combined with other issues may indicate confusion. However, the real compilation error stems from mismatched function declarations and definitions regarding return types and usage.]
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
            pop(stack); // @@ [The return value of pop() is ignored. According to the problem, popped values must be printed. Also, if pop() returns nothing in the error case, undefined behavior occurs because the function is expected to return an int always. This leads to missing output and potential runtime issues, but more critically, the function design causes logical errors that may manifest as incorrect output or crashes, though the immediate issue reported is a compilation error due to missing headers or environment. However, given the "gcc: not found" message is environmental, the actual code has semantic/logical errors that prevent correct behavior. But per instructions, we focus on code errors causing deviation from expected behavior. The core issue here is that pop() doesn't always return a value, which is undefined behavior in C and may cause compilation warnings or errors with strict settings.]
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
    if(isempty(stack)) printf("error "); // @@ [This branch does not return a value, but the function is declared to return int. This results in undefined behavior and is a critical error. In C, failing to return a value from a non-void function is undefined behavior and may cause compilation errors or crashes.]
    else return stack[top--];
}