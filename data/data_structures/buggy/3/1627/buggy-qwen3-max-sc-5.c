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
        int m = i; @@ // The variable 'm' is assigned but never used correctly; logic for trailing zero removal is flawed and may access invalid indices.
        if (k == 0) {
            while (a[i - 2] == '0') { @@ // Potential out-of-bounds access: when input has no decimal point and only one digit, i-2 could be negative or invalid.
                i--;
            }
        }
        printf("%c", a[0]);
        if (i > 2) {
            printf(".");
        }
        for (int j = 1; j < i - 2; j++) { @@ // Loop condition may skip necessary digits or cause off-by-one errors due to incorrect bounds (should likely be j < i - 1).
            if (j == k) {
                continue;
            } else {
                printf("%c", a[j]);
            }
        }
        if (k == 0)
            printf("e%d", m - 2); @@ // Incorrect exponent calculation when there's no decimal point; should reflect number of digits minus 1, not m-2.
        else
            printf("e%d", k - 1);
    }
    return 0;
}