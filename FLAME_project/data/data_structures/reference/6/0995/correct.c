#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef struct stack
{
    int data[105];
    int top;
}STACK;
void push(STACK *,int);
void pop(STACK *);
int main()
{
    int opr,data;
    STACK data_stack;
    STACK *p=&data_stack;
    p->top=-1;
    while(scanf("%d",&opr)!=EOF){
        if(opr==-1)break;
        switch (opr)
        {
        case 1:
            scanf("%d",&data);
            push(p,data);
            break;
        case 0:
            pop(p);
            break;
        default:
            break;
        }
    }
    return 0;
}
void push(STACK *p,int data)
{
    if(p->top==Maxsize-1){
        printf("error ");
        return;
    }
    p->data[++(p->top)]=data;
}
void pop(STACK *p)
{
    if(p->top==-1){
        printf("error ");
        return;
    }
    printf("%d ",p->data[(p->top)--]);
    return;
}
