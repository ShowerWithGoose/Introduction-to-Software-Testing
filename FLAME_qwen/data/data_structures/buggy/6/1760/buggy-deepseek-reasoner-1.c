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
            if (pop() == -1) { // @@ Calling pop() to check emptiness also pops an element if not empty, losing it.
                printf("error ");
            } else {
                printf("%d ", pop()); // @@ Calls pop() again, causing a second unintended pop and printing the wrong element.
            }

        }
        scanf("%d", &n);
    }
    return 0;
}