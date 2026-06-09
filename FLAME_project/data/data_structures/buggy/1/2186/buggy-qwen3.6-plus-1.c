#include <stdio.h>

void f(int *a, int *b, int n, int index) {

    int i = 0;
    if (index == n) {
        for (int i = 0; i < n; i++) {

            printf("%d", a[i]); // @@ The output format is incorrect. Integers should be separated by a space, e.g., printf("%d ", a[i]); or handle the last element separately to avoid trailing space if strictly required, but typically "%d " is accepted or "%d%c". Given expected output "1 2 ", a space after each number including the last one might be expected based on reference, or just between. Let's look at expected: "1 2 ". It seems there is a space after 2 as well in some judges, or just "1 2". The reference program prints "%d " for all. The buggy code prints "%d" with no spaces.
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