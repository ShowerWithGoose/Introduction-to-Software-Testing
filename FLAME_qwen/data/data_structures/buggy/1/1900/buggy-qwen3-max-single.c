#include <stdio.h>
int a[105];
int b[105];

void pailie(int *a, int *b, int n, int depth) {
    if (depth == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]); // @@ [Missing space between numbers as required by output format; should be "%d "]
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
    pailie(a, b, n, 1); // @@ [Missing return 0; may cause undefined behavior in some environments, though not strictly a compilation error. However, the reported error is "gcc: not found", which is not a code issue. But since the problem states to find errors in the program and the output format is wrong, the real issue is in printf formatting. Also note: the function uses global arrays but passes them as parameters unnecessarily, but that's not an error. The critical output format error is missing space.]
}