#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 101 // @@ MAX should be 100 to correctly represent the maximum capacity of 100.
typedef struct Stack {
    int stack[MAX];
    int top;
} *SqStack;

void initStack(SqStack S) {
    S->top=-1;
}
int push(SqStack S, int x) {
    if(S->top==MAX-2) { // @@ Condition should be S->top == MAX - 1 to properly check if the stack is full.
        return -1;
        
    }
    else {
        S->top++;
        S->stack[S->top]=x;
        return S->stack[S->top];
    }
}

int pop(SqStack S) {
    if(S->top==-1) {
        return -1;
    }
    else {
        return S->stack[S->top--];
    }
}

int main() {
    SqStack stack=malloc(sizeof(struct Stack));
    initStack(stack);
    int jud,x;
    while(scanf("%d",&jud)!=-1) { // @@ scanf returns EOF on end of input, and the loop should explicitly break when jud == -1 as per problem description.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ Output format requires "error " followed by a space, not a newline.
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ Output format requires "error " followed by a space, not a newline.
            }
            else {
                printf("%d\n",q); // @@ Output format requires all outputs on a single line separated by spaces, so use "%d " instead of "%d\n".
            }
        }
    }
}