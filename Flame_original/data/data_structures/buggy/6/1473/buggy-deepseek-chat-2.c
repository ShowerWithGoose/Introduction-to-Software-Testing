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
    if(S->top==MAX-2) { // @@ The condition should be S->top == MAX-1 to check if the stack is full (since top starts at -1 and MAX is 101, the last valid index is 100). Using MAX-2 incorrectly allows pushing when top is 99, but the stack can hold up to index 100.
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
    SqStack stack=malloc(sizeof(struct Stack)); // @@ The malloc return should be cast to (SqStack) for proper type assignment, though in C it may work without cast; more critically, the memory allocation might fail and return NULL, which is not checked.
    initStack(stack);
    int jud,x;
    while(scanf("%d",&jud)!=-1) { // @@ The loop condition should check for -1 as the end-of-operations marker, but scanf returns the number of items read, not -1. The loop should break when jud == -1 after reading.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ The problem requires outputting "error " (with a space after it), not "error\n". The output format should have a space after each element, including "error".
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ Same issue: should be "error " with a space, not "error\n".
            }
            else {
                printf("%d\n",q); // @@ The output format requires a space after each popped element, not a newline. Should be "%d " instead of "%d\n".
            }
        }
    }
}