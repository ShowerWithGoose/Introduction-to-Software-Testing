#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct s{
    int data[MAX];
    int top;
    int bottom;
}stack;
stack *StackCreate(){
    stack *p=(stack*)malloc(sizeof(stack));
    p->top=0;
    p->bottom=0;
    return p;
}
int a=0,type;
void Stackinput(stack *p,int num)
{
    p->data[p->top]=num;
    p->top++;
}
int stackoutput(stack *p)
{
    int temp=p->data[p->top]; // @@ [Error: top points to the next available index, so the actual top element is at p->top-1. Accessing p->data[p->top] reads out-of-bounds/uninitialized memory.]
    p->top--;
    return temp;
}
int stackcheck(stack *p)
{
    if(p->top==p->bottom)
        return 0;
    else 
        return 1;
}
int main()
{
    stack *aaa=StackCreate();
    scanf("%d",&type);
    while(type!=-1)
    {
        if(type==1)
        {
            scanf("%d",&a);
            Stackinput(aaa,a); // @@ [Error: Missing check for stack full condition. Should verify if aaa->top == MAX before pushing, and print "error " if full.]
        }
        if(type==0)
        {
            if(stackcheck(aaa)==1)
            {
                printf("%d ",stackoutput(aaa));
            }
            else
                printf("error ");
        }
        scanf("%d",&type);
    }
    return 0;
}