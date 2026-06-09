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
        printf("Error: Stack is full.\n"); // @@ [The problem expects "error " (lowercase, no colon, no newline), but this prints a different message with newline]
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ [The problem expects "error " (with a space, not newline), but this prints "error\n"]
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
            printf("Invalid operation.\n"); // @@ [The problem does not mention handling invalid operations; any non -1/0/1 input should not occur per spec, but printing here may cause extra output]
        }
    }

    return 0;
}