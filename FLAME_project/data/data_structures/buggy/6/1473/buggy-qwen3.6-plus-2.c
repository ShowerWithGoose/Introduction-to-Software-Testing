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
    if(S->top==MAX-2) { // @@ The maximum capacity is 100 (indices 0-99). The check should be S->top == MAX - 1 (or 99) to detect when the stack is full before pushing. Using MAX-2 causes an "error" to be returned when there is still one slot available, and potentially allows overflow if not handled correctly elsewhere, though here it just returns -1 prematurely. More importantly, the problem states max capacity 100. If top is 99, it's full. So check should be S->top >= MAX - 1.
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
    while(scanf("%d",&jud)!=-1) { // @@ scanf returns the number of items successfully read. It does not return -1 at EOF typically (it returns EOF which is usually -1, but the loop condition logic is fragile). However, the bigger issue is the output format.
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ The problem requires outputting "error " (with a space) and all outputs on a single line separated by spaces. Using \n breaks the single-line requirement.
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ The problem requires outputting "error " (with a space) and all outputs on a single line separated by spaces. Using \n breaks the single-line requirement.
            }
            else {
                printf("%d\n",q); // @@ The problem requires outputting elements separated by spaces on a single line. Using \n prints each element on a new line. It should be printf("%d ", q);
            }
        }
    }
}