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
                printf("error "); @@ [Calling pop() twice: first in condition, then again in printf. This causes two pops instead of one, leading to incorrect output and potential underflow.]
            } else {
                printf("%d ", pop()); @@ [Second call to pop() here causes the next element to be popped, not the intended one. Should store result of first pop() in a variable.]
            }

        }
        scanf("%d", &n);
    }
    return 0;
}