#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 102
struct op
{
    int data[M];
    int top;
}s;

int a,i;
typedef struct op op;
void ini(op *s)
{
s->top=-1;
}
int empty(op *s)
{
return s->top==-1;
}
int full(op *s)
{
return s->top==M-1;
}
int push(op *s,int a)
{
    if(full(s)!=0)
    {
        printf("error ");
        return 0;
    }
    s->data[++s->top]=a;
    return 1;
}
int pop(op *s,int a)
{
    if(s->top==-1)
    {
        printf("error ");
        return 0;
    }
    a=s->data[s->top--];
    printf("%d ",a);
    return 1;
}
int main(void)
{
    ini(&s);
    int type=-1;
    while(1)
    {
        scanf("%d", &type);
        if(type==-1)
            break;
        else if(type==0)
            pop(&s,a);
        else if(type==1)
        {
            scanf("%d",&i);
            push(&s,i);
        }
    }
}



