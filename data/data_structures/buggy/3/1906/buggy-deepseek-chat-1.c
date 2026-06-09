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
            printf("%c.", a[i]);
        else
            printf("%c", a[i]);
        i++;
        for (i; i <= N - 1; i++) {
            printf("%c", a[i]);
        }
        printf("e-%d", N - 2); // @@ Error: The exponent calculation is incorrect. For numbers like "0.001", the exponent should be -3 (number of leading zeros after decimal point), but N-2 gives 5-2=3, which is wrong. The correct exponent should be based on the position of the first non-zero digit after the decimal point.
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
            for (int s = 2; s <= N - 1; s++) {
                printf("%c", a[s]);
            }
            printf("e%d", N - 1); // @@ Error: For integers without decimal point, the exponent should be N-1 (e.g., "123" -> 1.23e2), but this is correct. However, the loop starts from s=2, skipping the second digit, which is wrong. It should start from s=1 to include all digits after the first.
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
            printf("e%d", M - 1); // @@ Error: The exponent calculation is incorrect. For numbers like "12.34", M is the index of the decimal point (2), so M-1=1, but the correct exponent should be 1 (since 12.34 = 1.234e1). However, for numbers like "1.23", M=1, M-1=0, which is correct. The issue is that the exponent should be the number of digits before the decimal point minus 1, which is M-1, but this fails for cases where the first digit is 0 (handled in the if branch). Actually, this is correct for non-zero first digit cases.
        }
    }
    return 0;
}