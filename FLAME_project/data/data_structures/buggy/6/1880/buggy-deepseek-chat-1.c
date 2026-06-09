#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 200
int stack[MAXSIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAXSIZE - 1;
}

void push(int a) {
    if (isFull()) {
        printf("error ");
    } else {
        stack[++top] = a;
    }

}

void pop() {
    if (isEmpty()) {
        puts("error "); // @@ [Using puts() adds a newline after "error ", but the expected output has no newline. Should use printf("error ") instead.]
    } else {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int a;
    scanf("%d", &a);
    while (a != -1) {
        if (a == 1) {
            scanf("%d", &a);
            push(a);
        } else {
            pop();
        }
        scanf("%d", &a); // @@ [After reading the operation code, the next read should be the next operation code, but when a==1, the value to push is read into a, overwriting the operation code. This causes the loop to misinterpret subsequent inputs.]
    }

}