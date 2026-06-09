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
        int m = i; @@ // The variable 'm' is assigned but never correctly used to compute exponent when there's no decimal point; also, trailing zeros are stripped incorrectly.
        if (k == 0) {
            while (a[i - 2] == '0') { @@ // This loop may access invalid memory (e.g., if input has only one digit), and doesn't handle cases where all digits after first are zero properly.
                i--;
            }
        }
        printf("%c", a[0]);
        if (i > 2) {
            printf(".");
        }
        for (int j = 1; j < i - 2; j++) { @@ // Loop bound 'i - 2' skips the last character before '\n', but input reading includes newline; this causes missing digits or out-of-bound reads.
            if (j == k) {
                continue;
            } else {
                printf("%c", a[j]);
            }
        }
        if (k == 0)
            printf("e%d", m - 2); @@ // Incorrect exponent: 'm - 2' doesn't reflect actual number of digits moved; should be based on original length minus 1.
        else
            printf("e%d", k - 1);
    }
    return 0;
}