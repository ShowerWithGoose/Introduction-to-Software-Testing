#include<stdio.h>
#include<stdlib.h>
#define init_size 100
typedef struct S{
    int *base;
    int *top;
    int stacksize;
}Stack;
int InitStack(Stack *St);
int Judge_full(Stack *St);
int Judge_null(Stack *St);
void Push(Stack *St,int num);
void Pop(Stack *St);
int main()
{
    int x,len = 0,data;
    Stack *St = (Stack *)malloc(sizeof(Stack));
    InitStack(St);
    scanf("%d",&x);
    while(x!=-1){
        switch(x){
            case 0:
            Pop(St);
            break;
            case 1:
            scanf("%d",&data);
            Push(St,data);
            break;
        }
        scanf("%d",&x);
    }
    return 0;
}
int Judge_full(Stack *St)
{
    if(St->top-St->base== St->stacksize-1)return 1;
    else return 0;
}
int Judge_null(Stack *St)
{
    if(St->top == St->base)return 1;
    else return 0;
}
int InitStack(Stack *St)
{
    St->base = (int *)malloc(init_size*sizeof(int));
    if(St->base == NULL)return 0;
    St->top=St->base;
    St->stacksize=init_size;
    return 1;
}
void Push(Stack *St,int num)
{
    if(Judge_full(St))printf("error ");
    *St->top=num;
    St->top++;
}
void Pop(Stack *St)
{
    if(Judge_null(St))
    {
        printf("error ");
        return;
    }
    St->top--;
    printf("%d ",*St->top);
}
