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
        int m = i; @@ [Variable 'm' is assigned but never used correctly; logic for trailing zeros removal is flawed and may access invalid memory]
        if (k == 0) {
            while (a[i - 2] == '0') { @@ [This loop may underflow the array if all digits are zero or if input length is small; also, it doesn't handle newline properly]
                i--;
            }
        }
        printf("%c", a[0]);
        if (i > 2) {
            printf(".");
        }
        for (int j = 1; j < i - 2; j++) { @@ [Loop condition skips last character(s) incorrectly; should account for newline and decimal point removal properly]
            if (j == k) {
                continue;
            } else {
                printf("%c", a[j]);
            }
        }
        if (k == 0)
            printf("e%d", m - 2); @@ [Uses 'm' which was set before modifying 'i', leading to incorrect exponent]
        else
            printf("e%d", k - 1);
    }
    return 0;
}