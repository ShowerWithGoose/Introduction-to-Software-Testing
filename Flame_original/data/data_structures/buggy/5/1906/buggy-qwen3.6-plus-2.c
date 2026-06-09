#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int a[100] = {0}, b[100] = {0}, c[100] = {0}, d[100] = {0}, ans[100][2] = {0}; // @@ The size of ans array is too small. Multiplying two polynomials with up to 50 terms each can produce up to 2500 terms, causing buffer overflow. It should be at least ans[2500][2].
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
    for (int s = 0; s < m; s++) { // @@ Declaring loop variable inside for loop is not supported in C89 standard, which causes compilation error on strict compilers. Declare 's' before the loop.
        for (int t = 0; t < n; t++) { // @@ Same C89 compatibility issue for variable 't'.
            ans[l][0] = a[s] * c[t]; // @@ Multiplying two int coefficients may exceed the int range. Use long long for coefficients to prevent overflow.
            ans[l][1] = b[s] + d[t];
            l++;
        }
    }
    for (int k = 0; k < l; k++) { // @@ Same C89 compatibility issue for variable 'k'.
        for (int s = k + 1; s < l; s++) { // @@ Same C89 compatibility issue for variable 's'.
            if (ans[s][1] == ans[k][1]) {
                ans[k][0] = ans[k][0] + ans[s][0];
                ans[s][0] = 0;
            }
        }
    }
    int temp1, temp2;
    for (int s = 0; s < l; s++) { // @@ Same C89 compatibility issue for variable 's'.
        int flag = 0;
        for (int t = s + 1; t < l; t++) { // @@ Same C89 compatibility issue for variable 't'.
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
            break;
        }
    }
    for (int k = 0; k < l; k++) { // @@ Same C89 compatibility issue for variable 'k'.
        if (ans[k][0] != 0) {
            printf("%d %d ", ans[k][0], ans[k][1]);
        }
    }
    return 0;
}