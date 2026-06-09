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
            pf ("%d", a[i]); // @@ [Missing space after each number; should be "%d " to match expected output format]
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