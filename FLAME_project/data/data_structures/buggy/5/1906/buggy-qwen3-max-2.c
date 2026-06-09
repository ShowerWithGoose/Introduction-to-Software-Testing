#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int a[100] = {0}, b[100] = {0}, c[100] = {0}, d[100] = {0}, ans[100][2] = {0};
    int i = 0, j = 0;
    for (i;; i++) {
        scanf("%d%d", &a[i], &b[i]);
        if (getchar() == '\n') {
            break;
        }
    }
    for (j;; j++) {
        scanf("%d%d", &c[j], &d[j]);
        if (getchar() == '\n')
            break;
    }
    int m = i + 1, n = j + 1, l = 0;
    for (int s = 0; s < m; s++) {
        for (int t = 0; t < n; t++) {
            ans[l][0] = a[s] * c[t];
            ans[l][1] = b[s] + d[t];
            l++;
        }
    }
    for (int k = 0; k < l; k++) {
        for (int s = k + 1; s < l; s++) {
            if (ans[s][1] == ans[k][1]) {
                ans[k][0] = ans[k][0] + ans[s][0];
                ans[s][0] = 0; // @@ [This sets the coefficient to zero but does not prevent it from being considered in later sorting or output; however, the real issue is that combining like terms should happen after sorting or in a way that doesn't miss duplicates. But more critically, this approach may double-add or miss terms because it only merges forward and doesn't handle all duplicates correctly when multiple same exponents exist beyond pairwise.]
            }
        }
    }
    int temp1, temp2;
    for (int s = 0; s < l; s++) {
        int flag = 0;
        for (int t = s + 1; t < l; t++) {
            if (ans[s][1] < ans[t][1]) {
                temp1 = ans[s][0];
                ans[s][0] = ans[t][0];
                ans[t][0] = temp1;
                temp2 = ans[s][1];
                ans[s][1] = ans[t][1];
                ans[t][1] = temp2;
                flag = 1;
            }
        }
        if (flag == 0) {
            break; // @@ [This early break assumes the list is fully sorted once one pass finds no swaps, but the sorting algorithm used is a variant of bubble sort that requires multiple full passes to guarantee correctness. Breaking early may leave the array partially sorted, leading to incorrect term ordering.]
        }
    }
    for (int k = 0; k < l; k++) {
        if (ans[k][0] != 0) {
            printf("%d %d ", ans[k][0], ans[k][1]);
        }
    }
    return 0;
}