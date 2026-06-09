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
                n = 1 - i; // @@ Error: The exponent calculation is incorrect. For input "0.00000009123456789012", the first non-zero digit '9' is at index 9 (0-based), so the exponent should be -8 (since the decimal point is at index 1, and the first significant digit is at index 9, the exponent is 1 - 9 = -8). However, the formula n = 1 - i gives n = 1 - 9 = -8, which is correct for this case, but the subsequent loop logic for printing the mantissa is flawed, causing the wrong digit to be printed.
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) { // @@ Error: The loop bound and indexing are incorrect. For input "0.00000009123456789012", n = -8, so l + n - 2 = 24 + (-8) - 2 = 14. The loop runs from i=0 to 14, but the indexing s[i + 1 - n] = s[i + 1 - (-8)] = s[i + 9] starts from s[9] (which is '9'), but the expected output should start with '9' (the first significant digit). However, the loop also includes i=0 and i=1, which print s[9] and s[10] respectively, but the condition `if (i == 1) printf(".")` places the decimal point after the first digit, which is correct. The problem is that the loop prints s[9] for i=0, then a dot for i=1, then s[10] for i=2, etc. This should produce "9.123456789012" but the buggy output shows "9.23456789012", indicating that the digit '1' is missing. This is because the loop starts at i=0 and prints s[9] (which is '9'), then for i=1 prints a dot, then for i=2 prints s[11] (since i+9=11), skipping s[10] which is '1'. The indexing is off by one.
            if (i == 1)
                printf(".");
            if (s[i] != '.')
                printf("%c", s[i + 1 - n]); // @@ Error: The index calculation s[i + 1 - n] is incorrect. For i=0, it gives s[9] (correct first digit). For i=1, it gives s[10] but the dot is printed instead. For i=2, it gives s[11], skipping s[10] which should be the second digit. The correct index should be s[i + 2 - n] or adjust the loop to start from the first significant digit properly.
        }
        printf("e%d", n);
    }

    return 0;
}