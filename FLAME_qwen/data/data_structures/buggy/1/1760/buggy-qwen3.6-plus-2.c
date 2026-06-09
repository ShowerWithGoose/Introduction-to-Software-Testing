#include <stdio.h>

int mark[10] = {0}; // @@ Array size should be 11 to safely access index 10 when N=10, otherwise it causes out-of-bounds access.
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ The output format requires spaces between integers, but puts prints the string without separators.
        return;
    }
    for (int i = 1; i <= n; i++) { // @@ Declaring loop variable 'i' inside the for statement is not supported in C89/C90 standards, which causes a compilation error in strict environments.
        if (mark[i] == 0) {
            mark[i] = 1;
            stack[m] = '0' + i;
            pl(m + 1, n);
            mark[i] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pl(0, n);
    return 0;
}