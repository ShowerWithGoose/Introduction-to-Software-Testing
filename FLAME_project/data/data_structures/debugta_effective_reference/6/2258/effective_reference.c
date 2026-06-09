#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

typedef struct  Stack{
    int *data;
    int top;
    int size;
}Stack;

Stack *initStack(int n){
    Stack *s=malloc(sizeof(Stack));
    s->data=malloc(sizeof(int )*n);
    s->top=0;
    s->size=n;
    return s;
}

int push(Stack *stack,int element){
    if(stack->top==stack->size)return 0;
    stack->data[stack->top++]=element;
    return 1;
}
void pop(Stack *stack){
    if(stack->top==0)return ;
    stack->top--;
    return ;
}

int peek(Stack *stack){
    if(stack->top==0)return 0;
    return stack->data[stack->top-1];
}


int main(){
    int operation;
    Stack *s=initStack(100);
    while(~scanf("%d",&operation)){
        switch (operation) {
            case 0:{
                if(!peek(s))printf("error ");
                else{
                    printf("%d ",peek(s));
                    pop(s);
                }
            }break;
            case 1:{
                int element;
                scanf("%d",&element);
                if(!push(s,element))printf("error ");
                
            }break;
            default:
                exit(0);
        }
    }
}

