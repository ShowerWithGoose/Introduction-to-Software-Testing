#include <stdio.h>

void f(int *a, int *b, int n, int index) {

    int i = 0;
    if (index == n) {
        for (int i = 0; i < n; i++) {

            printf("%d", a[i]); // @@ Missing space before each number. Should be "%d " to match expected output format (space-separated integers).
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {

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