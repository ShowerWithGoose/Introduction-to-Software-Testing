#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef int SElemType;
typedef struct{
    SElemType *top;
    SElemType *base;
    int stacksize;
}Stack;

Status InitStack(Stack* S)
{
    S->base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType));
    if(!S->base) 
        return -1;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return 1;
}

Status Push(Stack* S, SElemType* e){
if(S->top - S->base >= S->stacksize)
{
    S->base = (SElemType *) realloc (S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
    if(!S->base) 
        return -1;
    S->top = S->base + S->stacksize;
    S->stacksize += STACKINCREMENT;
}
    *(S->top) = *e;
    S->top++;
    return 1;
}

Status Pop(Stack* S, SElemType* e)
{
    if(S->base == S->top) 
        return -1;
    S->top--;
    *e = *(S->top);
    return 1;
}

int StackLength(Stack* S)
{
 return(S->top-S->base);
}

int main(){
    Stack SS;
    SElemType ee;
    int n;
    InitStack(&SS);
    while (scanf("%d", &n) != -1){
        if(n==1){
            if(SS.top-SS.base==STACK_INIT_SIZE)
                printf("error ");
            else{
                scanf("%d", &ee);
                Push(&SS, &ee);
            }
        }   
        if(n==0){
            if(SS.top-SS.base==0)
                printf("error ");
            else{
                Pop(&SS, &ee);
                printf("%d ", ee);
            }
        }
        
    }
    return 0;
}





