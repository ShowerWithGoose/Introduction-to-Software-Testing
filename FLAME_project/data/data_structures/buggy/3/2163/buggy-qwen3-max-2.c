#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') {
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) { // @@ [This loop is redundant and incorrectly increments `sum` again, leading to wrong exponent calculation. It also doesn't skip the decimal point correctly.]
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2;
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1];
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]); // @@ [This prints a decimal point even when there are no digits after it, violating the requirement that integers in scientific notation should not have a decimal point if only one digit is present. For input "0.9", this results in "9." instead of "9".]
        }
        printf("e-%d", sum);

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') {
        int sum = len - 2;

        printf("%se0", shuzi); // @@ [This prints the original number with "e0", but according to the problem, if there's only one non-zero digit before the decimal point (like "5.6"), it should be printed as-is with "e0", which is correct. However, this branch may not handle all valid cases properly, but it's not the cause of the given test case failure.]
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { // @@ [Reusing loop variable `i` inside another loop causes undefined behavior and incorrect copying. The outer `i` is modified by the inner loop, breaking logic.]
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { // @@ [Same issue: redeclaring `i` in nested loop leads to incorrect indexing and potential buffer overruns.]
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); // @@ [If the number has more than one digit before the decimal (e.g., "123.45"), this may print extra digits or malformed base due to incorrect copying in the loops above. Also, it always prints a decimal point even if trailing digits after decimal are absent, which may violate output format.]
    }

    return 0;
}