#include <stdio.h>

int mark[10] = {0}; // @@ Array size should be mark[11] for N up to 10 (indices 1..10)
char stack[11]; // @@ Array size too small; need at least 20 for N=10 (10 digits + 9 spaces + null)

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0'; // @@ Missing spaces between numbers; should have inserted spaces in the string
        puts(stack); // @@ Output lacks spaces, should be "1 2" not "12"
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            stack[m] = '0' + i; // @@ Only stores digit; missing space after digit (except last)
            pl(m + 1, n); // @@ Recursion should advance by 2 (digit and space), not by 1
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