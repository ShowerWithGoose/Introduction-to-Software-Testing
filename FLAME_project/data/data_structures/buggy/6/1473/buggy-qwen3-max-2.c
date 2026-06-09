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
    if(S->top==MAX-2) { @@ // The condition should be S->top == MAX - 1 because the stack has MAX capacity (indices 0 to MAX-1). Using MAX-2 incorrectly reduces capacity by 1.
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
    while(scanf("%d",&jud)!=-1) { @@ // The loop condition is incorrect. scanf returns the number of successfully read items, not the value read. It should check for EOF or compare jud after reading. Also, the problem requires stopping at -1, but this loop never breaks on jud == -1.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); @@ // Output format requires a space after each element/error, not a newline.
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); @@ // Output format requires a space after each element/error, not a newline.
            }
            else {
                printf("%d\n",q); @@ // Output format requires a space after each element/error, not a newline.
            }
        }
    }
}