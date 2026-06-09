#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAXSIZE 1000
int  STACK[MAXSIZE];
int  Top=-1,a;
void push(int s[ ], int a){
    if(Top==MAXSIZE-1)
    printf("error ");
    else
    s[++Top]=a;}
int pop(int s[])
{
    if(Top==-1)
    printf("error ");
    else
    printf("%d ",s[Top--]);
}
int main()
{
    int x,n;
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x==1)
        {
            scanf("%d",&n);
            push(STACK,n);
        }
        if(x==0)
        {
            pop(STACK);
        }
        scanf("%d",&x);
    }
return 0;
}
