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
                n = 1 - i;
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) { @@ [The loop condition and index calculation are incorrect, causing the first significant digit to be skipped and leading to wrong mantissa output. Specifically, `s[i + 1 - n]` skips the first non-zero digit because of off-by-one error in indexing.]
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i + 1 - n]); @@ [This expression `s[i + 1 - n]` is flawed: when `n = 1 - i0` (where `i0` is the index of first non-zero digit), then `1 - n = i0`, so it should be `s[i0 + i]`, but current logic misaligns the output starting position, skipping the correct first digit.]
        }
        printf("e%d", n);
    }

    return 0;
}