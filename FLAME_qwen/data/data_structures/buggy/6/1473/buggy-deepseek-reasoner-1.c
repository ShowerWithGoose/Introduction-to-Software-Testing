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
    if(S->top==MAX-2) {
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
    while(scanf("%d",&jud)!=-1) { // @@ 错误：输入终止条件应为读入-1时结束，而不是依靠scanf返回-1（文件结束）。应改为 while(1) { scanf("%d",&jud); if(jud==-1) break; ... }
        if(jud==1) {
            scanf("%d",&x);
            int p;
            p=push(stack,x);
            if(p==-1) {
                printf("error\n"); // @@ 错误：输出格式应为 "error "（带空格，无换行），这里输出了换行符。
            }
        }
        else if(jud==0) {
            int q;
            q=pop(stack);
            if(q==-1) {
                printf("error\n"); // @@ 错误：同上，应输出 "error " 而不是 "error\n"。
            }
            else {
                printf("%d\n",q); // @@ 错误：输出格式应为 "%d "（数字后跟空格，无换行），这里输出了换行。
            }
        }
    }
}