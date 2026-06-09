#include <stdio.h>
#include <string.h>
char w[1000];
char h[1000];
char y[1000];

int main() {
    gets(w);
    int len_w = strlen(w);
    int y = 0, g = -1;
    for (int i = 0; i < len_w; i++) {
        if (w[i] != '.') {
            h[y] = w[i];
            y++;
        } else if (w[i] == '.') {
            g = i;
            g = g - 1; // @@ The calculation of the exponent 'g' is incorrect for numbers less than 1 (e.g., 0.9). For "0.9", g becomes 0, but the expected exponent is -1. The exponent should be calculated based on the position of the first significant digit relative to the decimal point.
        }
    }
    if (h[1] == '0') { // @@ This condition checks if the second significant digit is '0'. For input "0.9", h is "09", so h[1] is '9'. This condition fails, leading to the else block which formats it as a decimal with exponent 0, producing "0.9e0" instead of "9e-1". The logic for handling numbers starting with "0." (less than 1) is flawed.
        int flag = 0;
        int i;
        for (i = 0; h[i] == '0'; i++) {
            flag++;
        }
        while (h[i] != '\0') {
            printf("%c", h[i]);
            i++;
        }
        printf("e-");
        printf("%d", flag);
//完成了收个数为0的情况
    } else {
        printf("%c", h[0]);
        printf(".");
        int t = 1;
        while (h[t] != '\0') {
            printf("%c", h[t]);
            t++;
        }
        printf("e");
        printf("%d", g); // @@ For input "0.9", g is 0 here due to the earlier error. It prints "0.9e0". The correct output should be "9e-1". The base should be just "9" (integer) if there are no other significant digits after the first one in the mantissa for this specific case format, or "9.0..." if following strict rules, but the problem says "If it’s an integer, it contains only one significant digit without a decimal point". Since 0.9 -> 9 * 10^-1, the base is 9. The code always prints a decimal point.
    }
}