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
            if (pop() == -1) { // @@ [Error: pop() is called twice - once in the condition and once in the else branch, causing one extra pop and losing the popped value. The first pop() in the condition removes the element from the stack, so the second pop() in the else branch pops the next element instead of printing the first one.]
                printf("error ");
            } else {
                printf("%d ", pop()); // @@ [Error: This calls pop() again, which pops and prints the next element, not the one checked in the condition. The correct approach is to store the result of pop() in a variable and use it.]
            }

        }
        scanf("%d", &n);
    }
    return 0;
}