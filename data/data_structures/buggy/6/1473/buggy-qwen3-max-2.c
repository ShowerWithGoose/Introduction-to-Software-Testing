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
    if(S->top==MAX-2) { @@ // The stack capacity is MAX (101), so valid indices are 0 to 100. The condition should be `S->top == MAX - 1` to check if full. Using `MAX-2` incorrectly allows one extra push beyond capacity.
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
    while(scanf("%d",&jud)!=-1) { @@ // The loop condition is incorrect. `scanf` returns the number of successfully read items (1 on success), not the value read. It should be `while(scanf("%d", &jud) == 1 && jud != -1)` or similar. As written, it never breaks on `-1` and may cause infinite loop or undefined behavior.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); @@ // Output format requires space-separated values on a single line with a space after each element, including "error". Using `\n` violates the output format.
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); @@ // Same issue: should print "error " (with space, no newline) to match expected output format.
            }
            else {
                printf("%d\n",q); @@ // Should print "%d " (with trailing space), not newline, per output specification.
            }
        }
    }
}