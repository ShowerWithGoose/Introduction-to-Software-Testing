#include <stdio.h>
int read();
int st[102], top;
int main() {
    while (1) {
        int op = read(), x;
        if (op == -1) break;
        if (op == 0) {
            if (!top)
                printf("error ");
            else
                printf("%d ", st[top]), --top;
        } else {
            x = read();
            if (top == 100)
                printf("error ");
            else
                st[++top] = x;
        }
    }
    return 0;
}

int read() {
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9') (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
