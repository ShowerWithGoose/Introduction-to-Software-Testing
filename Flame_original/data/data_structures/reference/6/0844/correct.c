#include<stdio.h>
#include<stdlib.h>
typedef struct Stack *Stack;
struct Stack{
    int Capacity;
    int *stack;
    int top;
};
Stack CreateStack(int C){
    Stack S=malloc(sizeof(struct Stack));
    S->Capacity=C;
    S->stack=malloc(sizeof(int)*(S->Capacity+1));
    S->top=0;
    return S;
}
int IsEmpty(Stack S){
    return S->top==0;
}
int IsFull(Stack S){
    return S->top>=S->Capacity;
}
void Pop(Stack S){
    if(IsEmpty(S))
        printf("error ");
    else
        printf("%d ",S->stack[--S->top]);
}
// int Top(Stack S){   
//     return S->stack[S->top];
// }
void Push(int x,Stack S){
    if(IsFull(S))
        printf("error ");
    else
        S->stack[S->top++]=x;
}
int main(void){
    Stack S=CreateStack(100);
    for(;;){
        int op,x;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            Push(x,S);
        }
        else if(op==0){
            Pop(S);
        }
        else if(op==-1){
            break;
        }
    }
    free(S);
    return 0;
}
