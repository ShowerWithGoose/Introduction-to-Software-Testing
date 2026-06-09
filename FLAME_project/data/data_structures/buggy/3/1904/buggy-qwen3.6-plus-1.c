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
                n = 1 - i; // @@ The calculation of the exponent is incorrect. For input "0.00...09...", if the first non-zero digit is at index i, the exponent should be -(i-1). Here n becomes 1-i, which is correct for the exponent value (negative), but let's check the usage. If i=2 (0.9), n=-1. Correct. If i=10 (0.00...9), n=-9. Correct. So the exponent value `n` is actually correct as `1-i` or `-(i-1)`. Wait, standard scientific notation for 0.0091 is 9.1e-3. Index of 9 is 3. n = 1-3 = -2. Expected -3? No. 0.0091 = 9.1 * 10^-3. Index 0='0', 1='.', 2='0', 3='0', 4='9'. If i=4, n=1-4=-3. Correct.
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) { // @@ The loop condition and body logic for extracting the significant digits are flawed. It attempts to print characters based on an offset that doesn't correctly align with the source string to extract the sequence starting from the first non-zero digit. Specifically, `s[i + 1 - n]` accesses indices incorrectly relative to the desired output sequence, leading to skipped or wrong characters (like skipping the '1' in the example).
            if (i == 1)
                printf(".");
            if (s[i] != '.') // @@ This condition checks the wrong character for validity in the context of the shifted index, and combined with the loop range, it fails to reproduce the significant digits correctly after the decimal point.
                printf("%c", s[i + 1 - n]); // @@ The index calculation `i + 1 - n` is incorrect for mapping the output position `i` to the source string position. For the first significant digit at source index `first_non_zero`, we want to print it at output index 0. If `i=0`, index should be `first_non_zero`. Here `1-n` equals `first_non_zero` (since `n = 1 - first_non_zero`). So `s[0 + first_non_zero]` is correct for the first char. However, subsequent characters are not handled correctly because the loop bound `l + n - 2` and the simple linear mapping don't account for the decimal point removal and proper termination correctly in all cases, especially causing the missing digit in the specific test case.
        }
        printf("e%d", n);
    }

    return 0;
}