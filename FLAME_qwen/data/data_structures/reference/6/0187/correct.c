#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef int ElemType;
typedef struct SNode *Stack;
struct SNode{
    ElemType data[Maxsize];
    int top;
};
Stack S;
Stack CreatStack(); //初始化堆栈
int IsFull(Stack S); //判断堆栈是否已满
int IsEmpty(Stack S); //判断堆栈是否为空
void Push(Stack S,ElemType item ); //入栈
ElemType Pop(Stack S); //出栈
Stack CreatStack()
{
    S=(Stack)malloc(sizeof(struct SNode));
    S->top=-1;
    return S;
}
int IsFull(Stack S)
{
    return (S->top==Maxsize-1);
}
int IsEmpty(Stack S)
{
    return (S->top==-1);
}
void Push(Stack S,ElemType item)
{
    if(IsFull(S)){
        printf("error ");
        return ;
    }
    else{
        S->top++;
        S->data[S->top]=item;
        return;
    }
}
ElemType Pop(Stack S){
    if(IsEmpty(S)){
        printf("error ");
        return 0;
    }
    else{
        ElemType val=S->data[S->top];
        S->top--;
        return val;
    }
}
int main()
{
    int a,b;
    Stack S=CreatStack();
    scanf("%d",&a);
    while(a!=-1)
    {
        if(a==0){
            b=Pop(S);
            if(b!=0) printf("%d ",b);
            scanf("%d",&a);
        }
        else if(a==1){
            scanf("%d",&b);
            Push(S,b);
            scanf("%d",&a);
        }
    }
    return 0;
}
