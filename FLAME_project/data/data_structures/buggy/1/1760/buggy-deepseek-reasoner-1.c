#include <stdio.h>

int mark[10] = {0}; // @@ array size too small for N=10, accessing index 10 is out of bounds
char stack[11]; // @@ array size insufficient if spaces are added; also missing spaces in output

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            stack[m] = '0' + i; // @@ should also add a space after the digit and increase m by 2 accordingly
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