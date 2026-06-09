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
                n = 1 - i; // @@ The calculation of the exponent is incorrect. For input "0.00000009...", the first non-zero digit '9' is at index 9. The exponent should be -(number of zeros after decimal point + 1) or simply index of dot - index of first sig digit. Here n becomes 1-9 = -8, which is correct for the exponent value, but let's check the printing logic.
                break;
            }
        }
        for (int i = 0; i <= l + n - 2; i++) { // @@ The loop condition and indexing for printing the mantissa are incorrect. It skips the first significant digit because of the offset logic `s[i + 1 - n]` combined with the loop start and end conditions. Specifically, when i=0, it prints s[1-n]. If n=-8, it prints s[9], which is '9'. This part seems to grab the right character for the first position. However, the loop bound `l + n - 2` is likely wrong, causing truncation or out-of-bounds access, and the logic `if (i == 1) printf(".")` assumes the decimal point is always after the first printed character, which is correct for scientific notation, but the source characters being pulled are shifted incorrectly for subsequent digits.
            if (i == 1)
                printf(".");
            if (s[i] != '.') // @@ This check is flawed because `s[i]` is checking the original string at index `i`, but we are printing characters from `s[i + 1 - n]`. We should be checking if the character being *printed* is a dot, or simply ensuring we don't print the original dot if it falls into the range. More critically, the logic `if (s[i] != '.')` filters based on the wrong index.
                printf("%c", s[i + 1 - n]); // @@ The index `i + 1 - n` is incorrect for mapping the output position `i` to the source string position for all digits. It works for the first digit (i=0 -> idx 9) but fails for others. For i=2 (after dot), we want the next digit '1' at s[10]. Formula: 2 + 1 - (-8) = 11. s[11] is '2'. We skipped '1'. The mapping is off by one or more depending on position relative to the original decimal point.
        }
        printf("e%d", n);
    }

    return 0;
}