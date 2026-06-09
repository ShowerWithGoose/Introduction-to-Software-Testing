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
        printf("Error: Stack is full.\n"); // @@ Error: The problem requires outputting "error " (with a space) for a full stack push, not "Error: Stack is full.\n". Also, the program should not exit or print extra newlines.
    } else {
        Stack[++top] = item;
    }
}

ElemType pop() {
    if (isEmpty()) {
        printf("error\n"); // @@ Error: The problem requires outputting "error " (with a space, no newline) for an empty stack pop, not "error\n". Also, returning -1 may conflict with valid data values; the reference program handles this differently.
        return -1; // @@ Error: Returning -1 as a sentinel value is problematic because -1 could be a valid pushed integer. The reference program does not return a value from pop() when empty; it just prints "error ".
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
            if (item != -1) { // @@ Error: This condition incorrectly filters out valid popped values that happen to be -1, and also fails to print "error " when pop fails (since pop() prints "error\n" instead).
                printf("%d ", item);
            }
        } else {
            printf("Invalid operation.\n"); // @@ Error: The problem specification only includes operations 1, 0, and -1; no "Invalid operation" output is required.
        }
    }

    return 0;
}