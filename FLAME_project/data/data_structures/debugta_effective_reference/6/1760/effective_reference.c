#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxsize 100

int stack[maxsize];
int top=-1;


int isFull();
int isEmpty();
void push(int stack[],int n);
void pop(int stack[]);


int main()
{
    int op,n;
    do{
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            scanf("%d",&n);
            push(stack,n);
            break;
        case 0:
            pop(stack);
            break;
        }
    }while(op!=-1);

    return 0;
}

int isFull()
{
    return top==maxsize-1;
}

int isEmpty()
{
    return top==-1;
}

void push(int stack[],int n)
{
    if(isFull())
    {
        printf("error ");
    }else{
       stack[++top]=n;
    }
}

void pop(int stack[])
{
    if(isEmpty())
    {
         printf("error ");
    }else{
        printf("%d ",stack[top--]);
    }
}


