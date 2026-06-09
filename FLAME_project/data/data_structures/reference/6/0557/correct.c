#include <stdio.h>
#define MAXSIZE 120
#define POP 0
#define PUSH 1
#define END -1

void push(int x);
void pop(void);

typedef struct stack{
    int data[MAXSIZE];
    int top;
} stack;

stack s;
int main() {
    s.top = -1;
    int op, x;
    while (scanf("%d", &op) != EOF) {
        if (op == 1) {
            scanf("%d", &x);
            push(x);
        }
        if (op == 0) {
            pop();
        }
        if (op == -1) {
            break;
        }
    }
    return 0;
}
void push(int x){
    if (s.top == MAXSIZE-1) {
        printf("error ");//错误处理
    }else{
        s.data[++s.top] = x;//入栈

    }
}

void pop(void){
    if (s.top == -1) {
        printf("error ");//错误处理
    }else{
        printf("%d ", s.data[s.top--]);//出栈
    }
}

