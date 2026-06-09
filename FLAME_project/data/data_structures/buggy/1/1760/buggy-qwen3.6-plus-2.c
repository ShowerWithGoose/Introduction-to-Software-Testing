#include <stdio.h>

int mark[10] = {0};
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ The output format is incorrect. The problem requires integers to be separated by a space (e.g., "1 2"), but this code outputs them consecutively (e.g., "12") because spaces are not added between the digits in the stack.
        return;
    }
    for (int i = 1; i <= n; i++) {
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