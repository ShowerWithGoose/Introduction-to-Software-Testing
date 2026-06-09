#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 100

int stack[maxsize];
int top;

void initstack(int stcak[]);
int isempty(int stack[]);
int isfull(int stack[]);
void push(int stack[],int item);

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
            if(isempty(stack)) printf("error ");
            else printf("%d ",stack[top--]);
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




