#include <stdio.h>
#include <string.h>

int main() {
    char a[110] = {'\0'};
    gets(a);
    int N = strlen(a);
    if (a[0] == '0' && N != 1) {
        int i = 2;
        while (a[i] == '0') {
            i = i + 1;
        }
        int j = i;
        if ((N - j) != 1)
            printf("%c.", a[i]); // @@ Error: When there are trailing digits after the first non-zero digit, the base should include a decimal point and all subsequent digits. However, this logic incorrectly handles cases where the number is like "0.001" (only one significant digit after zeros). The condition (N - j) != 1 is flawed; it should check if there are more digits after the first non-zero digit to decide whether to print a decimal point.
        else
            printf("%c", a[i]);
        i++;
        for (i; i <= N - 1; i++) {
            printf("%c", a[i]);
        }
        printf("e-%d", N - 2); // @@ Error: The exponent calculation is incorrect. For numbers like "0.001", the exponent should be -3 (since 0.001 = 1e-3), but N - 2 gives 4 - 2 = 2, which is wrong. The exponent should be based on the number of zeros after the decimal point, not simply N - 2.
    } else {
        int temp = 0;
        for (int j = 0; j <= N - 1; j++) {
            if (a[j] == '.') {
                temp = 1;
                break;
            }
        }
        if (temp == 0 && N == 1) {
            printf("%ce0", a[0]);
        } else if (temp == 0 && N != 1) {
            printf("%c.", a[0]);
            for (int s = 2; s <= N - 1; s++) { // @@ Error: This loop starts from index 2, skipping index 1. For an integer like "123", it should print "1.23e2", but this loop prints only digits from index 2 onward, missing the digit at index 1.
                printf("%c", a[s]);
            }
            printf("e%d", N - 1);
        } else {
            int M;
            printf("%c.", a[0]);
            for (int t = 1; t <= N - 1; t++) {
                if (a[t] != '.') {
                    printf("%c", a[t]);
                } else {
                    M = t;
                }
            }
            printf("e%d", M - 1); // @@ Error: The exponent calculation is incorrect. For a number like "123.45", the exponent should be 2 (since 1.2345e2), but M - 1 gives the position of the decimal point minus 1, which is 3 - 1 = 2, which happens to be correct for this case. However, for numbers like "1.23", M = 1, so M - 1 = 0, but the exponent should be 0 (since 1.23e0). This logic fails for numbers with only one digit before the decimal point.
        }
    }
    return 0;
}