#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 200 // @@ [should be 100 to match problem's maximum capacity of 100; using 200 may cause push to succeed when it should output "error"]
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
        puts("error "); // @@ [puts adds a newline; should be printf("error ") to match the required output format "error " without newline]
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