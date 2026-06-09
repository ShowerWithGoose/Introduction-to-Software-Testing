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
        puts("error "); // @@ [Using puts() adds a newline character, but the problem requires output with only spaces and no newlines. Should use printf("error ") instead.]
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
        scanf("%d", &a); // @@ [If the input ends with -1 immediately after a pop or push, this extra scanf may attempt to read beyond the provided input, potentially causing undefined behavior or hanging. The loop condition should check input success before using 'a'. Also, the reference program uses while(~scanf(...)), which correctly handles EOF and input termination.]
    }

}