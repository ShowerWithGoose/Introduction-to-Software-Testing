#include <stdio.h>

int mark[10] = {0}; // @@ [Array size is too small; for N=10, indices 1..10 are used, but array only has 10 elements (0..9), causing out-of-bounds access]
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ [Output format uses puts which adds a newline, but each number should be separated by space and the line should end with newline; current output prints digits without spaces between them]
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