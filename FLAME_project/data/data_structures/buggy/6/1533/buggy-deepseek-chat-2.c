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
    else if(n==-1); // @@ [Error: Semicolon after else if condition causes the break to execute unconditionally, so the loop breaks after any input, not just -1. Remove the semicolon to fix.]
    break; // @@ [Error: This break is outside the else if block due to the semicolon above, causing the loop to exit after the first iteration regardless of input.]
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