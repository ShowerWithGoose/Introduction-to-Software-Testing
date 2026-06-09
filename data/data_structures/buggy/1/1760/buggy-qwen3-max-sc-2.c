#include <stdio.h>

int mark[10] = {0}; // @@ [Array size is too small; for N=10, indices 1..10 are used, but mark[10] is out of bounds for an array of size 10 (valid indices: 0..9)]
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ [Output format is incorrect: puts adds a newline, but the problem requires space-separated integers on each line without extra spaces or missing newlines; also, this prints characters like '1', '2', etc., but as single chars without spaces between them when n>1]
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