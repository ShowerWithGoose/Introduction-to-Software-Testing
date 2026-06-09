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
            if (pop() == -1) { // @@ [Error: pop() is called twice - once in the condition and once in the else branch, causing double popping and incorrect output. The first pop() in the condition removes an element, then the second pop() in the else branch removes the next element, so the popped value printed is not the one that was checked for emptiness.]
                printf("error ");
            } else {
                printf("%d ", pop()); // @@ [Error: This calls pop() again, popping a second element instead of printing the one popped in the condition. Should store the result of pop() in a variable first.]
            }

        }
        scanf("%d", &n);
    }
    return 0;
}