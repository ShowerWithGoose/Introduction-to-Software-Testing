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
        printf("e-%d", N - 2); // @@ [The exponent calculation is incorrect. It should be based on the position of the first non-zero digit after the decimal point, not the total length. For input "0.00000009123456789012", the first non-zero digit '9' is at index 8 (0-based), so exponent should be -(8 - 1) = -7, but due to off-by-one and wrong formula, it outputs -20 or similar. Correct exponent is -(i - 1), not N - 2.]
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
            for (int s = 2; s <= N - 1; s++) { // @@ [This loop starts at index 2, skipping a[1], which is incorrect. If there's no decimal point and N > 1 (e.g., "123"), then after printing a[0] and '.', it should print from a[1] onward, not a[2]. This causes missing digits.]
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
            printf("e%d", M - 1);
        }
    }
    return 0;
}