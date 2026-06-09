#include<stdio.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top=-1;
void push(int s[],int item);
void pop(int s[]);
int main(int argc,const char*argv[])
{
    while(1)
    {
    int n,m;
    scanf("%d",&n);
    if(n==1)
    {
        scanf("%d",&m);
        push(STACK,m);
    }
    else if(n==0)
    pop(STACK);
    else if(n==-1); // @@ The semicolon here terminates the else-if statement prematurely, causing the subsequent 'break' to execute unconditionally after the first iteration or logic flow issue, effectively breaking the loop immediately after checking -1 or even earlier depending on structure. Specifically, `else if(n==-1);` does nothing when n is -1, and then `break;` is executed regardless of the value of n because it is no longer part of the conditional block. This causes the loop to terminate after the first input if n is not 1 or 0, or potentially behave incorrectly. In this specific case, if n is -1, the condition is checked, the empty statement executes, then break executes. If n is 1 or 0, the corresponding block executes, then the code falls through to `break;` because `break;` is outside the if-else chain due to the semicolon. Wait, let's trace: if n==1, push happens. Then the if-else chain ends. The next line is `break;`. So the loop breaks after ONE iteration regardless of input. This is why the output is empty for input `1 567 0 -1`. The loop runs once, reads 1, pushes 567. Then hits `break`. Exits. Never processes 0 or -1.
    break;
    }
    return 0;
}
void push(int s[],int item)
{
    if(Top==MAXSIZE-1)
    printf("error ");
    else 
    s[++Top]=item;
}
void pop(int s[])
{
    if(Top==-1)
    printf("error ");
    else
    printf("%d ",s[Top--]); 
}