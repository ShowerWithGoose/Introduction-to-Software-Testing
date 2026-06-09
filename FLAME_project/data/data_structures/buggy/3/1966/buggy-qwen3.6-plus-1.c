#include <stdio.h>
#include <string.h>
#include <math.h>

void f(int x, int y, char s[]);

int main() {
    char s[103];
    scanf("%s", s);
    int i, j, len, hold = 0, x;
    len = strlen(s);

    if (s[0] == '-') {
        printf("-");
        if (s[1] == '0') {
            for (i = 3; i < len; i++) {
                if (s[i] >= '1' && s[i] <= '9') {
                    if (i == len - 1) {
                        printf("%ce-", s[i]);
                    } else {
                        printf("%c.", s[i]);
                        f(i + 1, len, s); // @@ The function f prints the remaining digits and then prints "e". This results in the exponent being printed after the "e" from f, but the logic here also prints "-" and the exponent value. The structure is flawed because f already prints "e", leading to duplicate or misplaced 'e's and exponents. Specifically, f prints "e" at the end of its execution, so calling f(i+1, len, s) will print the rest of the number followed by "e". Then the code prints "-" and the exponent. This results in output like "9.123...e-8" if handled correctly, but f prints "e" unconditionally.
                    }
                    printf("%d", hold + 1);
                } else {
                    hold++;
                }
            }
        } else {
            printf("%d.", s[1]); // @@ Incorrect format specifier. s[1] is a char, but %d expects an int. It should be %c to print the character digit. Using %d will print the ASCII value of the character.
            f(3, len, s);
            for (i = 1; i < len; i++) {
                if (s[i] == '.')
                    hold = i;
            }
            printf("%d", hold - 2);
        }
    } else {
        if (s[0] == '0') {
            for (i = 2; i < len; i++) {
                if (s[i] >= '1' && s[i] <= '9') {
                    if (i == len - 1) {
                        printf("%ce-", s[i]);
                    } else {
                        printf("%c.", s[i]);
                        f(i + 1, len, s); // @@ Similar error as above. f prints the remaining digits and an "e". Then the code prints "-" and the exponent. This leads to malformed output like "9.123...e-8" but potentially with extra characters or incorrect ordering if f's internal "e" interferes. The main issue is that f appends "e" unconditionally.
                    }
                    printf("%d", hold + 1);
                } else {
                    hold++;
                }
            }
        } else {
            printf("%c.", s[0]);
            f(1, len, s); // @@ f prints digits from index 1 onwards (skipping s[0] which was already printed) until the end, skipping non-digits (like '.'), and then prints "e". However, the loop in f iterates through the whole string remainder. If the input is "12.34", s[0]='1' is printed. f(1, len, s) prints '2', '3', '4' then 'e'. Then the main function calculates the exponent. The output would be "1.234e...". Wait, f skips '.', so it prints "234e". The output becomes "1.234e...". This part might be logically okay for the mantissa, but let's check the exponent calculation.
            for (i = 1; i < len; i++) {
                if (s[i] == '.')
                    hold = i;
            }
            printf("%d", hold - 1);
        }
    }
    return 0;
}

void f(int x, int y, char s[]) {
    int i = x;
    for (i; i < y; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            printf("%c", s[i]);

    }
    printf("e"); // @@ This function always prints "e" at the end. In the calling context, especially for the "pure decimal" cases (0.xxx), the caller prints "-", then the exponent. So the output becomes [mantissa]e-[exponent]. But f prints "e" before the caller prints "-" and the exponent. So it looks like [mantissa]e-[exponent]. This seems correct for the format IF the caller doesn't print another 'e'. However, in the `if (i == len - 1)` branch, the caller prints "%ce-", which includes 'e'. In the `else` branch, the caller relies on f to print 'e'. This inconsistency and the fact that f prints 'e' unconditionally causes issues. For the case 0.0000000912..., the first non-zero is at index 9 ('9'). i=9. len=22. i != len-1. So it goes to else. Prints "9.". Calls f(10, 22, s). f prints "123456789012" then "e". Then caller prints "-" and "8". Result: "9.123456789012e-8". This actually looks correct for this specific case. 
    // Let's re-read the buggy output: "9.123456789012e-81.23456789012e-82.3456789012e-83.4..."
    // This suggests the loop continues! The `break` is missing in the `if (s[i] >= '1' ...)` block after handling the first significant digit.
}