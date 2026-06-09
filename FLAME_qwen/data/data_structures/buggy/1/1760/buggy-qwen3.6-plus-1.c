#include <stdio.h>

int mark[10] = {0}; // @@ Array size is insufficient for N=10. Accessing mark[10] when i=10 causes an out-of-bounds error. Should be mark[11].
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ Output format mismatch. The problem requires integers to be separated by spaces, but puts prints the concatenated characters without spaces.
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