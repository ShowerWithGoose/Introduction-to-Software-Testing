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
            stack[m] = '0' + i; // @@ [This stores only the digit character without a space separator, causing all numbers to be concatenated without spaces. Also, for N=2, it writes '1' at index 0 and '2' at index 1, then null-terminates at index 2, resulting in "12" instead of "1 2".]
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