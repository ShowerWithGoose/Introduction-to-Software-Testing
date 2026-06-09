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
        puts("error "); // @@ The problem requires outputting "error " (with a space) using printf, but puts() adds a newline, which does not match the expected output format.
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
        scanf("%d", &a); // @@ This reads the next operation after processing the current one, but if a pop operation (0) is processed, the next integer read should be the next operation, not a value to push. However, the logic is correct for the given input format. The issue is that when a == 1, the code reads the value to push into 'a', overwriting the operation code, then pushes it, and then reads the next operation. This works, but the problem is that after a pop, the next scanf reads the next operation, which is fine. However, the original reference program reads all input in a single while loop using ~scanf, which handles the input more robustly. This program's approach may fail if the input contains extra spaces or newlines, but the main error is in the pop function.
    }

}