#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
struct stack
{
    int data[100];
    int top;
};

int push(struct stack *L,int ele)
{
    if(L->top==99)
    {
        return 0;
    }
    L->data[L->top]=ele;
    L->top++;
    return ele;
}

int pop(struct stack *L)
{
    if(L->top==0)
    {
        return 0;
    }
    int val=L->data[L->top-1];
    printf("%d",val);
    L->top--;
    return val;
}

int isempty(struct stack *L)
{
    if(L->top!=0)
    {
        return 1;
    }
    return 0;
}

int isfull(struct stack *L)
{
    if(L->top!=99)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i,opr,ele;
    struct stack L;
    L.top=0;
    for(i=0;i<100;i++)
    {
        L.data[i]=0;
    }
    while(scanf("%d",&opr)!=EOF)
    {
        if(opr==1)
        {
            scanf("%d",&ele);
            if(isfull(&L)!=0)
            {
                push(&L,ele);
            }
            else
            {
                printf("error ");
            }
        }
        if(opr==0)
        {
            if(isempty(&L)!=0)
            {
                pop(&L);
                printf(" ");
            }
           else
           {
               printf("error ");
           }
        }
        if(opr==-1)
        {
            return 0;
        }
    }
    return 0;
}
