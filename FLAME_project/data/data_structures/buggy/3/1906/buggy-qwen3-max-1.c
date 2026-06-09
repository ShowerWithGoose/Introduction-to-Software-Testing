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
        printf("e-%d", N - 2); // @@ [The exponent calculation is incorrect. It should be based on the position of the first non-zero digit after the decimal point, not the total length. For "0.00000009123456789012", the first non-zero digit '9' is at index 8 (0-based), so exponent should be -(8-1) = -7? Wait: actually, in 0.00000009..., the '9' is the 8th digit after decimal (positions: . 0 1 2 3 4 5 6 7 8...), so it's at index 9 in string ("0."," then 7 zeros, then '9' at index 9). The correct exponent is -8 because 0.00000009 = 9e-8. The current code uses N-2 which is 20-2=18 for input length 20, leading to e-18 or similar. But actual bug: exponent should be (i - 2) with negative sign, because after "0.", each zero moves one place. So exponent = -(i - 2 + 1)? Let's see: for "0.00000009...", i starts at 2 (after "0."), increments until a[i]!='0'. At '9', i=9 (0:'0',1:'.',2:'0',3:'0',4:'0',5:'0',6:'0',7:'0',8:'0',9:'9'). So number of leading zeros after decimal is i-2 = 7, so value is 9.x * 10^-(7+1) = 10^-8. So exponent = -(i - 1). Because i=9, exponent = -8. So should be printf("e-%d", i - 1);]
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
            for (int s = 2; s <= N - 1; s++) { // @@ [This loop starts at s=2, but if there's no decimal point, the digits are contiguous from index 0. So after printing a[0] and '.', it should print from a[1] onward, not a[2]. This skips the second digit.]
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