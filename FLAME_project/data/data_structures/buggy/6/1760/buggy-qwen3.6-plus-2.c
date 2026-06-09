#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define M 100
int top = -1;
int stack[M];

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == M - 1;
}

void push(int item) {
    if (isFull()) {
        printf("error ");
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if (isEmpty()) {
        return -1;

    } else {
        return stack[top--];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n != -1) {
        if (n == 1) {
            scanf("%d", &n);
            push(n);
        } else if (n == 0) {
            if (pop() == -1) {
                printf("error ");
            } else {
                printf("%d ", pop()); // @@ The first call to pop() in the condition already removes the element from the stack. Calling pop() again here retrieves the next element (or error), causing the wrong output. The value returned by the first pop() should be stored and printed instead.
            }

        }
        scanf("%d", &n);
    }
    return 0;
}