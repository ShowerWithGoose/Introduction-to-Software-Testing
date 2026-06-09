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
        for (int i = 0; i <= l + n - 2; i++) { @@ [The loop condition and index calculation are incorrect, causing the output to skip the first significant digit after leading zeros. Specifically, `s[i + 1 - n]` starts reading from the wrong position, skipping the first non-zero digit.]
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i + 1 - n]); @@ [This indexing skips the first significant digit. For input "0.00000009123...", it starts printing from '2' instead of '9', because `1 - n` is miscalculated and used incorrectly as an offset.]
        }
        printf("e%d", n);
    }

    return 0;
}