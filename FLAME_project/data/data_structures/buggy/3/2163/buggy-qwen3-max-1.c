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

        for (int i = 0; i < len; i++) { @@ // This loop is redundant and incorrect: it reuses the same variable `sum` without resetting, leading to double counting of leading zeros.
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
            printf("%c", shuzi2[i]); @@ // This prints a decimal point even when there are no digits after it, violating the requirement that if the base is an integer (only one significant digit), it should not have a decimal point.
        }
        printf("e-%d", sum);

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') {
        int sum = len - 2;

        printf("%se0", shuzi); @@ // This prints the original number with "e0", but according to the problem, if there's only one non-zero digit before the decimal (like "5.3"), it should be printed as "5.3e0", which is acceptable. However, for input like "9.0" (not in test), it might fail. But more critically, this branch doesn't handle cases like "12.3" correctly—it's only triggered when the second character is '.', i.e., single-digit before decimal. However, the real issue is elsewhere.
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Reusing loop variable `i` inside a loop that already uses `i` causes undefined behavior and incorrect copying.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Same issue: redeclaring `i` in inner loop modifies outer loop variable, leading to incorrect logic and possible infinite loops or skipped characters.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // This prints the reconstructed string which may contain unnecessary trailing digits or decimal point when only one digit is needed (e.g., for "9", it should be "9e0", not "9.e0"). Also, for numbers like "123.45", it should output "1.2345e2", but due to incorrect copying, it may output wrong format.
    }

    return 0;
}