#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]); // @@ [Parameter name 'stcak' is misspelled; should be 'stack' for consistency, though not a compilation error by itself, but combined with other issues may indicate confusion]
int isempty(int stack[]);
int isfull(int stack[]);
void push(int stack[],int item);
int pop(int stack[]);

int main()
{
    int op,num;
    initstack(stack);
    while(scanf("%d ",&op)&&op!=-1) // @@ [The format string "%d " in scanf consumes trailing whitespace, which may cause the loop to wait for extra input after -1, potentially leading to unexpected behavior or infinite loop in some environments, but more critically: the condition checks op!=-1 AFTER reading, so if -1 is read, the loop body won't execute, which is correct. However, the real issue is below.]
    {
        if(op==1) 
        {
            scanf("%d ",&num); // @@ [Using "%d " again may cause input buffering issues; more importantly, the pop function's return value is ignored in main, and when pop succeeds, it returns the value but main doesn't print it. This causes missing output for successful pops. Also, when pop fails, it prints "error ", but when it succeeds, main does nothing with the returned value — so no popped elements are printed. This is a logical error causing wrong output, but the problem states the error type is Compilation Error. However, the actual compilation error comes from another line.]
            push(stack,num);
        }
        else if(op==0)
        {
            pop(stack); // @@ [The return value of pop() is not used. When pop succeeds, it returns the popped value, but main doesn't print it. So successful pops produce no output. This is a logical error, but again, the reported error is Compilation Error. The true compilation error is elsewhere.]
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
    else return stack[top--]; // @@ [This function has a control path that does not return a value when the stack is empty. In C, this leads to undefined behavior, and many compilers will issue a warning or error (especially with stricter settings). Since the function is declared to return 'int', but in the 'if' branch it only prints and does not return anything, this causes a compilation error in standards-compliant compilers or under certain flags. This is the primary compilation error.]
}