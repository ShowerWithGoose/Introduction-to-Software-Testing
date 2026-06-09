#include <stdio.h>

void f(int *a, int *b, int n, int index) {

    int i = 0;
    if (index == n) {
        for (int i = 0; i < n; i++) { // @@ Compilation error in C89: cannot declare variable inside for loop; should use a previously declared variable or declare at block start.

            printf("%d", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) { // @@ Compilation error in C89: same issue as above; variable i already declared in outer scope.

        if (b[i] == 0) {

            a[index] = i;

            b[i] = 1;

            f(a, b, n, index + 1);
            b[i] = 0;

        }
    }

}

int main() {
    int n;
    int a[100] = {0};
    int b[100] = {0};
    scanf("%d", &n);
    f(a, b, n, 0);
    return 0;

}