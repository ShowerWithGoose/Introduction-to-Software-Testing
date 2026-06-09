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
        puts("error "); // @@ [Using puts() adds a newline, but the problem requires space-separated output on a single line. Should use printf("error ") instead.]
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
        scanf("%d", &a); // @@ [If the first scanf fails (e.g., due to invalid input or EOF), this second scanf may read uninitialized or incorrect data. Also, after reading -1 inside the loop body, this extra scanf will attempt to read beyond the intended input, possibly causing undefined behavior or missing the termination condition correctly. The loop structure does not match the reference program's robust input handling using while(~scanf(...)).]
    }

}