#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 200 // @@ The problem specifies a maximum stack capacity of 100, not 200.
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
        puts("error "); // @@ puts() automatically appends a newline character, but the output format requires a space after "error". Use printf("error "); instead.
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
        scanf("%d", &a);
    }

}