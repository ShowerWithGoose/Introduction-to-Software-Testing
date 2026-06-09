#include<stdio.h>

int Stack[101];

typedef struct stack{
    int stacksize;
    int* base;
    int* top;
}JLstack;

void Push(JLstack *S,int num);
void Pop(JLstack *S);

int main(){
    int num;
    JLstack S;

    S.stacksize = 100;
    S.base = S.top = Stack;

    scanf("%d",&num);
    while(num != -1){
        switch (num) {
            case 1 :
                scanf("%d",&num);
                Push(&S,num);
                break;
            case 0 :
                Pop(&S);
                break;
        }
        scanf("%d",&num);
    }


    return 0;
}
void Push(JLstack *S,int num){
    if(S->top - S->base < S->stacksize){
        S->top++;
        *S->top = num;
    }else{
        printf("error ");
    }
}
void Pop(JLstack *S){
    if(S->top == S->base)
        printf("error ");
    else{
        printf("%d ",*S->top);
        S->top--;
    }
}
