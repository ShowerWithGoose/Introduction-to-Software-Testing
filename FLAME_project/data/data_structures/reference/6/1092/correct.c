#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int stack[MAX];
int top;
void initStack()
{
    top=-1;
}
int isEmpty()
{
    return top==-1;
}
int isFull()
{
    return top==MAX-1;
}
void push(int s[],int item)
{
    if(isFull())
      printf("error ");
    else
      s[++top]=item;
}
int pop(int s[])
{
    return s[top--];
}
int main()
{
    initStack();
    int op,a;
    do{
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&a);
            push(stack,a);
        }
        else if(op==0)
        {
           if(isEmpty())
            printf("error ");
           else
            printf("%d ",pop(stack));
        }
        else if(op==-1) return 0;
    }while(op!=-1);
    return 0;
}


