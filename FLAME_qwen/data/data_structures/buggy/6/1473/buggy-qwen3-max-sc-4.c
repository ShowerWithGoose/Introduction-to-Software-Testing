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
    if(S->top==MAX-2) { @@ // The stack capacity is MAX (101), so valid indices are 0 to 100. The condition should be `S->top == MAX - 1` to check if full. Using `MAX-2` allows pushing one extra element beyond intended capacity.
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
    while(scanf("%d",&jud)!=-1) { @@ // The loop condition is incorrect. `scanf` returns the number of successfully read items, not the value read. It should continue until `jud == -1`, but this condition will never break on input `-1` because `scanf` returns 1 (success), not -1. Also, the problem says `-1` terminates the sequence, so the loop should break when `jud == -1`.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); @@ // The problem requires outputting "error " (with a space) on a single line for all errors and popped values, but this prints "error\n". Also, multiple outputs should be space-separated on one line, not newline-separated.
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); @@ // Same issue: should print "error " with a space, not newline.
            }
            else {
                printf("%d\n",q); @@ // Should print "%d " with a space, not newline, to match expected output format.
            }
        }
    }
}