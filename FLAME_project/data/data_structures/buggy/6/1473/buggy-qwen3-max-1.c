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
    if(S->top==MAX-2) { @@ // The condition should be S->top == MAX - 1 because the stack size is MAX (101), valid indices are 0 to 100. When top is 99 (MAX-2), there's still room for one more element. Error occurs when trying to push beyond index 100.
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
    while(scanf("%d",&jud)!=-1) { @@ // The loop condition is incorrect. scanf returns the number of successfully read items, not the value read. It should be while(scanf("%d", &jud) == 1). Also, the problem requires stopping when -1 is read, but this loop never checks for -1 as a termination condition properly.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); @@ // Output format requires space-separated values on a single line with a space after each element, including "error ". Using \n is incorrect.
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