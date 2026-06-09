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
    else if(n==-1); // @@ The semicolon here terminates the else-if statement prematurely, causing the subsequent 'break' to execute unconditionally after the first iteration or logic flow issue, effectively breaking the loop immediately after checking for -1 regardless of whether it was -1 or not in the intended block structure. Actually, strictly speaking, `else if(n==-1);` does nothing if n is -1. Then `break;` is executed ALWAYS because it is outside the if-else chain due to the semicolon. This causes the loop to terminate after the first operation regardless of input.
    break; // @@ This line is executed unconditionally because of the semicolon on the previous line. It should be inside the `else if(n==-1)` block.
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