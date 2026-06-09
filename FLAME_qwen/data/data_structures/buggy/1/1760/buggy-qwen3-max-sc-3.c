#include <stdio.h>

int mark[10] = {0}; // @@ [Array size is too small; for N=10, indices 1..10 are used, but mark[10] is out of bounds since array size is 10 (valid indices 0..9). Should be at least size 11.]
char stack[11];

void pl(int m, int n) {
    if (m == n) {
        stack[m] = '\0';
        puts(stack); // @@ [Output format requires space-separated integers and a newline; puts adds only '\n', but the string lacks spaces between digits. Also, for N>9, '0'+i fails as it produces non-digit characters.]
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            stack[m] = '0' + i; // @@ [This only works for i<=9; for i=10, '0'+10 is ':', not "10". Also, output should be space-separated numbers, not concatenated digits.]
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