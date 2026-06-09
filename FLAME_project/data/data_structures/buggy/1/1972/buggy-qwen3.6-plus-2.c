#include <stdio.h>
#include <math.h>
#define sf scanf
#define pf printf
#define ll long long
#define eps 1e-6
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void quanpai (int a[], int b[], int n, int depth) {
    if (depth == n + 1) {
        for (int i = 1; i <= n; i++) {
            pf ("%d", a[i]); // @@ The output format requires integers to be separated by a space. This line prints the number without a trailing space or separator, causing the output "12" instead of "1 2 ". It should be pf("%d ", a[i]); or handled with spacing logic.
        }

        pf ("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (b[i] == 0) {
                b[i] = 1;
                a[depth] = i;
                quanpai(a, b, n, depth + 1);
                b[i] = 0;
            }
        }
    }
}

int main() {
    int n;
    scanf ("%d", &n);
    int a[1005] = {0};
    int b[1005] = {0};
    quanpai(a, b, n, 1);
    return 0;
}