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
        printf("e-%d", N - 2); // @@ The exponent calculation is incorrect. For input "0.00...09...", the exponent should be -(position of first significant digit - 1). Here, if the first significant digit is at index i, the exponent is -(i-1). The current code uses N-2 which depends on the total length and trailing zeros, not the position of the significant digit. For "0.00000009123456789012", the first non-zero '9' is at index 9. The exponent should be -8. The code calculates N-2. N is 22. N-2 is 20. It prints e-20. It should be e-(i-1) where i is the index of the first non-zero digit after decimal. Wait, the variable i was incremented. Let's trace. i starts at 2. While loop finds first non-zero. For "0.00000009...", indices: 0:'0', 1:'.', 2:'0'... 9:'9'. So i becomes 9. j=9. Print a[9] which is '9'. Then i becomes 10. Loop prints rest. Exponent should be -(9-1) = -8. The code prints e-(N-2). N=22. e-20. This is wrong. The exponent should be calculated based on the position of the first significant digit.
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