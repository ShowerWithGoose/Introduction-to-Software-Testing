#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    gets(s);
    int l = strlen(s), n;
    if (s[0] != '0') {
        for (int i = 0; i <= l - 1; i++) {
            if (s[i] == '.') {
                n = i - 1;
                break;
            }
        }
        for (int i = 0; i <= l - 1; i++) {
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i]);
        }
        printf("e%d", n);
    } else {
        for (int i = 0; i <= l - 1; i++) {
            if (s[i] != '0' && s[i] != '.') {
                n = 1 - i; // @@ Error: The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at index 8 (0-based), so the exponent should be -8, but 1 - 8 = -7, leading to an off-by-one error.
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) {
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i + 1 - n]); // @@ Error: The index calculation for printing digits is incorrect due to the wrong exponent value, causing the first digit '9' to be printed instead of '1', and the subsequent digits to be misaligned.
        }
        printf("e%d", n);
    }

    return 0;
}