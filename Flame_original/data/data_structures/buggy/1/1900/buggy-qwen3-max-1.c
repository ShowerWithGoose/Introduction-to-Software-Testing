#include <stdio.h>
int a[105];
int b[105];

void pailie(int *a, int *b, int n, int depth) {
    if (depth == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]); // @@ [Missing space between numbers as required by output format]
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
    pailie(a, b, n, 1); // @@ [Missing return 0; may cause undefined behavior in some environments, though not strictly a compilation error. However, the primary issue is the missing space in output. Also note: the reported "Compilation Error" with "gcc: not found" is likely environmental, but based on code analysis, the real bug is output formatting.]
}