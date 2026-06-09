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
    else if(n==-1); // @@ [Empty statement; break on next line is always executed, causing loop to exit after first operation]
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