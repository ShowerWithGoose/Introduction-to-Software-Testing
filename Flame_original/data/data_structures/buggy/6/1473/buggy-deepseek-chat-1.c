#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 101
typedef struct Stack {
    int stack[MAX];
    int top;
} *SqStack;

void initStack(SqStack S) {
    S->top=-1;
}
int push(SqStack S, int x) {
    if(S->top==MAX-2) { // @@ The condition should be S->top == MAX-1 to check if the stack is full (since top starts at -1 and MAX is 101, the last valid index is 100)
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
    SqStack stack=malloc(sizeof(struct Stack)); // @@ Missing cast: should be (SqStack)malloc(sizeof(struct Stack)) to match the typedef
    initStack(stack);
    int jud,x;
    while(scanf("%d",&jud)!=-1) { // @@ The loop condition should check for -1 as the end-of-operations marker, but the input format uses -1 as a separate operation, not EOF. The loop should stop when jud == -1, not when scanf returns -1.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ Should print "error " (with a space, not newline) to match the expected output format
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ Should print "error " (with a space, not newline) to match the expected output format
            }
            else {
                printf("%d\n",q); // @@ Should print "%d " (with a space, not newline) to match the expected output format
            }
        }
    }
}