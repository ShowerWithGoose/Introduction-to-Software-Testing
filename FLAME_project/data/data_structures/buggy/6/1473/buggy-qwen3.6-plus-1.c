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
    if(S->top==MAX-2) { // @@ The condition for stack full is incorrect. With MAX=101 and indices 0-100, the stack is full when top == MAX-1 (100). Checking MAX-2 (99) causes an error when pushing the 100th element. It should be S->top == MAX - 1.
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
    while(scanf("%d",&jud)!=-1) { // @@ The loop termination condition is incorrect. scanf returns the number of successfully read items, not the value read. It will rarely return -1 (EOF) in this context as intended. The loop should continue until jud is -1, checked inside the loop.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ The output format requires "error " followed by a space, and popped elements should be on a single line separated by spaces. Using \n prints each on a new line or adds a newline incorrectly. It should be printf("error ");
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ Similar to above, the output format requires "error " with a space, not a newline. It should be printf("error ");
            }
            else {
                printf("%d\n",q); // @@ The output format requires all popped elements on a single line separated by spaces. Using \n prints each element on a new line. It should be printf("%d ", q);
            }
        }
    }
}