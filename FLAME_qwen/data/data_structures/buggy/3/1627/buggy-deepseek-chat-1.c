#include <stdio.h>

int main() {
    char a[9999];
    scanf("%c", &a[0]);
    if (a[0] == '0') {
        int i = 1, p = 9999;
        while (scanf("%c", &a[i]) != EOF) {
            if (a[i] != '0' && i > 1 && p > i)
                p = i;
            i++;
        }
        if (i - p == 2) {
            printf("%ce-%d", a[p], p - 1);
        } else {
            printf("%c.", a[p]);
            for (int j = p + 1; j < i - 1; j++) {
                printf("%c", a[j]);
            }
            printf("e-%d", p - 1);
        }
    } else {
        int i = 1, k = 0;
        while (scanf("%c", &a[i]) != EOF) {
            if (a[i] == '.') {
                k = i;
            }
            i++;
        }
        int m = i;
        if (k == 0) {
            while (a[i - 2] == '0') { // @@ The condition `a[i - 2] == '0'` may access out-of-bounds when `i` is small (e.g., i=2), and the logic incorrectly removes trailing zeros from an integer input, which is not required by the problem (all digits are significant, no trailing zeros after decimal point, but integers have no decimal point and should not have trailing zeros removed).
                i--;
            }
        }
        printf("%c", a[0]);
        if (i > 2) {
            printf(".");
        }
        for (int j = 1; j < i - 2; j++) {
            if (j == k) {
                continue;
            } else {
                printf("%c", a[j]);
            }
        }
        if (k == 0)
            printf("e%d", m - 2);
        else
            printf("e%d", k - 1);
    }
    return 0;
}