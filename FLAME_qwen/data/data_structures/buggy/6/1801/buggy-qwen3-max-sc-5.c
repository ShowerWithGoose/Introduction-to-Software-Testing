#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]); // @@ [Parameter name 'stcak' is misspelled; should be 'stack' for consistency, though not a compilation error by itself, but combined with other issues may indicate confusion. However, the real compilation errors are below.]

int isempty(int stack[]);
int isfull(int stack[]);
void push(int stack[],int item);
int pop(int stack[]);

int main()
{
    int op,num;
    initstack(stack);
    while(scanf("%d ",&op)&&op!=-1) // @@ [The format string "%d " in scanf consumes trailing whitespace, which may cause the loop to wait for extra input after -1, but more critically, the pop function's return value is ignored and not printed.]
    {
        if(op==1) 
        {
            scanf("%d ",&num); // @@ [Same issue with "%d " — may cause input reading problems, but not a compilation error. The critical issue is missing output of popped values.]
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ [The return value of pop() is not printed. According to the problem, popped elements must be output. Also, when stack is empty, "error " is printed inside pop(), but when not empty, the popped value is returned but never printed in main(). This leads to missing output.]
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
    else return stack[top--]; // @@ [When the stack is not empty, this returns the popped value, but the calling code in main() does not print it. Also, if the stack is empty, the function prints "error " but then falls through and returns an undefined value (since no return statement after printf), which is undefined behavior and may cause compilation warnings or runtime issues. The function must return an int in all paths.]
}