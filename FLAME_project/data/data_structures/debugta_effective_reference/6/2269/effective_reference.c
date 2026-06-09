#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxsize 100

int stack[maxsize];
int top=-1;


int isFull();
int isEmpty();
void push(int stack[],int a);
void pop(int stack[]);


int main()
{
    int op,a;
    do{
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            scanf("%d",&a);
            push(stack,a);
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

void push(int stack[],int a)
{
    if(isFull())
    {
        printf("error ");
    }else{
       stack[++top]=a;
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


