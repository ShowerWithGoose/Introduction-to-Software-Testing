#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 120
int stack[MAX_NUM], top = -1;

inline int read();
void push(int x);
void pop();

int main() {
    int op, num;
    while(1) {
        op = read();
        if (op == -1) {
            break;
        } else if (op == 1) {
            num = read();
            push(num);
        } else if (op == 0) {
            pop();
        }
    }
    system("pause");
    return 0;
}

inline int read() {
    int num = 0;
    int sign = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') {
            sign = -1;
        }
        ch = getchar();
    }
    while (isdigit(ch)) {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num * sign;
}

void push(int x) {
    if (top == 99) {
        printf("error ");
        return;
    } else {
        stack[++top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("error ");
        return;
    } else {
        printf("%d ", stack[top--]);
    }
}

