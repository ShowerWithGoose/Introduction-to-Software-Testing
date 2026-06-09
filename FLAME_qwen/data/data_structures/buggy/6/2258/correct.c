#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 入栈
void push(Stack *s, int element) {
    if (isFull(s)) {
        printf("error ");
        return;
    }
    s->data[++s->top] = element;
}

// 出栈
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("error ");
        return -1;  // 返回-1表示栈为空，出栈失败
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    initStack(&s);

    int operation, element;
    while (1) {
        scanf("%d", &operation);
        if (operation == -1) {
            break;
        }
        switch (operation) {
            case 1:  // 入栈操作
                scanf("%d", &element);
                push(&s, element);
                break;
            case 0:  // 出栈操作
                element = pop(&s);
                if (element != -1) {
                    printf("%d ", element);
                }
                break;
            default:
                printf("Invalid operation\n");
                break;
        }
    }

    return 0;
}

