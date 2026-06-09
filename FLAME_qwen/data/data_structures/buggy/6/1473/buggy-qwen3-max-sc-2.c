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
    if(S->top==MAX-2) { // @@ [The condition should be `S->top == MAX - 1` because the stack has MAX=101 elements (indices 0 to 100). When top is 99 (MAX-2), there's still room for one more element. The stack becomes full when top == 100 (i.e., MAX-1).]
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
    while(scanf("%d",&jud)!=-1) { // @@ [The loop condition `scanf(...) != -1` is incorrect. `scanf` returns the number of successfully read items, not EOF directly. It should check for `== 1` or compare with EOF properly. Also, the problem says input ends with -1 as an operation, not as a scanf failure. This causes infinite loop or wrong termination.]
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ [The problem requires outputting "error " (with a space and on the same line as other outputs), but this prints "error\n". Also, all outputs should be on one line separated by spaces, not newlines.]
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ [Same issue: should print "error " with a space, not newline.]
            }
            else {
                printf("%d\n",q); // @@ [Should print "%d " with a space, not newline, to match expected output format.]
            }
        }
    }
}