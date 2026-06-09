#include <stdio.h>
int a[105];
int b[105];

void pailie(int *a, int *b, int n, int depth) {
    if (depth == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]); // @@ Missing space between numbers; should be "%d " to match expected output format.
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            b[i] = 1;
            a[depth] = i;
            pailie(a, b, n, depth + 1);
            b[i] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    pailie(a, b, n, 1);
}