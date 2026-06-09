#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;
ElemType Stack[MAXSIZE];
int top = -1;

void initStack() {
    top = -1;
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAXSIZE - 1;
}

void push(ElemType item) {
    if (isFull()) {
        printf("Error: Stack is full.\n"); // @@ The error message should be "error " (lowercase, no colon, no newline, followed by space), not "Error: Stack is full.\n"
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ The error message should be "error " (followed by a space, not a newline)
        return -1; // 返回一个特殊值表示 pop 失败
    } else {
        return Stack[top--];
    }
}

int main() {
    int Element, item;
    initStack(); // 初始化栈

    while (1) {
        scanf("%d", &Element);
        if (Element == -1) {
            break; // 如果输入为 -1，则退出循环
        }
        if (Element == 1) {
            scanf("%d", &item);
            push(item);
        } else if (Element == 0) {
            item = pop();
            if (item != -1) {
                printf("%d ", item);
            }
        } else {
            printf("Invalid operation.\n"); // @@ According to problem description, only 1, 0, and -1 are valid inputs; this case should not occur, but printing anything here causes wrong output. Should not print anything for invalid ops, though input guarantees only valid ops.
        }
    }

    return 0;
}