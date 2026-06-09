#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXSIZE 100
void initstack();
int isempty();
int isfull();
int stack[MAXSIZE];
void push(int stack[],int num);
int pop(int stack[]);
int top;
int main()
{
    int op,num,popped,o;
    initstack();
    o=0;
    while(o==0)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            push(stack,num);
        }
        else if(op==0)
        {
            if(isempty(stack)==0)
            {
                popped=pop(stack);
                printf("%d ",popped);
            }
            else
            {
                printf("error ");
            }
        }
        else if(op==-1)
        {
            break;
        }
    }
    return 0;
}

void initstack()
{
    top=-1;
}

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if(top==MAXSIZE-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int stack[],int num)
{
    if(isfull()==1)
    {
        printf("error ");
    }
    else
    {
        stack[++top]=num;
    }
}

int pop(int stack[])
{
    if(isempty()==1)
    {
        printf("error ");
    }
    else
    {
        return stack[top--];
    }
}

