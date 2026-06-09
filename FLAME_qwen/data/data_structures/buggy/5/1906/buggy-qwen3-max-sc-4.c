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
                ans[s][0] = 0;
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
            break;
        }
    }
    for (int k = 0; k < l; k++) {
        if (ans[k][0] != 0) {
            printf("%d %d ", ans[k][0], ans[k][1]); // @@ [Using %d to print potentially large integers from multiplication may cause overflow; should use long long and %lld as in reference program]
        }
    }
    return 0;
}