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
            if (pop() == -1) { // @@ Calling pop() here modifies the stack state and consumes an element. It should check isEmpty() or store the returned value.
                printf("error ");
            } else {
                printf("%d ", pop()); // @@ Calling pop() again pops a second element instead of printing the first one. The value should be stored in a variable.
            }

        }
        scanf("%d", &n);
    }
    return 0;
}