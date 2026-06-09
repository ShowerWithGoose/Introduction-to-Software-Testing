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
            if (pop() == -1) { // @@ [Error: pop() is called twice - once in the condition and once in the else branch, causing one element to be lost and the wrong value to be printed. The first pop() removes the element, so the second pop() gets the next element or -1 if empty.]
                printf("error ");
            } else {
                printf("%d ", pop()); // @@ [Error: This calls pop() again, which pops and prints the next element instead of the one popped in the condition, resulting in incorrect output.]
            }

        }
        scanf("%d", &n);
    }
    return 0;
}