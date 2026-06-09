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
        printf("Error: Stack is full.\n"); // @@ [The problem expects "error " (lowercase, no colon, no newline), but this prints "Error: Stack is full.\n", which does not match the required output format.]
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ [The problem expects "error " (with a space, not a newline), but this prints "error\n", which adds a newline instead of a space and may cause formatting issues.]
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
            printf("Invalid operation.\n"); // @@ [The problem does not mention handling invalid operations (i.e., numbers other than -1, 0, or 1 followed by a value). According to the problem description, input only consists of valid operations, but this code prints an extra message for invalid ops, which is not expected and may cause wrong output.]
        }
    }

    return 0;
}