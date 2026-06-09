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
            while (a[i - 2] == '0') { @@ // This loop may underflow the array if all digits are zeros or if input length is small; also modifies 'i' which affects later indexing.
                i--;
            }
        }
        printf("%c", a[0]);
        if (i > 2) {
            printf(".");
        }
        for (int j = 1; j < i - 2; j++) { @@ // Loop bound 'i - 2' may skip necessary digits or cause out-of-bound reads depending on newline handling.
            if (j == k) {
                continue;
            } else {
                printf("%c", a[j]);
            }
        }
        if (k == 0)
            printf("e%d", m - 2); @@ // Uses 'm' (original 'i') instead of adjusted 'i', leading to incorrect exponent when trailing zeros are removed.
        else
            printf("e%d", k - 1);
    }
    return 0;
}