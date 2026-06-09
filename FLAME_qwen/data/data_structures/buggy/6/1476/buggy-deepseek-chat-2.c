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
        printf("Error: Stack is full.\n"); // @@ The problem requires outputting "error " (with a space) for a full stack, not "Error: Stack is full.\n"
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ The problem requires outputting "error " (with a space) for an empty stack, not "error\n"
        return -1; // @@ Returning -1 as a special value is incorrect because -1 could be a valid pushed element; the reference program does not return a value on error
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
            if (item != -1) { // @@ This condition incorrectly filters out valid popped values that happen to be -1; the reference program prints the popped value directly without such a check
                printf("%d ", item);
            }
        } else {
            printf("Invalid operation.\n"); // @@ The problem does not define this output; invalid operations should not occur based on the input specification
        }
    }

    return 0;
}