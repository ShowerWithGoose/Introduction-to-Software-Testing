#include <stdio.h>

int mark[10] = {0};
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            stack[m] = '0' + i; // @@ The output format requires integers to be separated by a space. This line only stores the digit character without adding a space separator, causing the output "12" instead of "1 2". Additionally, for N >= 10, '0' + i will not correctly represent multi-digit numbers.
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