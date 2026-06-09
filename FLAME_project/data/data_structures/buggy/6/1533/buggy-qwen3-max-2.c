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
    else if(n==-1); // @@ [The semicolon after the else if condition causes the break statement to execute unconditionally, terminating the loop immediately even when n is not -1. This leads to missing processing of subsequent operations.]
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