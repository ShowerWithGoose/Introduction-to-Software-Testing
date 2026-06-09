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
        scanf("%d", &a); // @@ This reads the next operation after processing the current one, but if the input is "1 x", after reading x into a, the next scanf will read the following operation. However, if the input ends with -1, this scanf may read beyond the input or cause issues with the loop condition. The reference program reads all input in a single while loop using ~scanf, which is more robust.
    }

}