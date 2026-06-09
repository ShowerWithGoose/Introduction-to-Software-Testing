#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { @@ // This condition assumes the second last character is '0', but input may not have trailing zeros; also fails when input has only one digit after decimal or no decimal at all.
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum); @@ // Incorrectly uses shuzi[len - 1] as significant digit; should find first non-zero after decimal. Also, logic for exponent is wrong.
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Assumes there's always a decimal point and at least two digits; fails on inputs like "0.1" or "0.001"
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++; @@ // This loop counts leading zeros including '.', but then another loop below adds more to sum incorrectly.
        }

        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0') {
                break;
            }
            sum++; @@ // Double counting of leading zeros leads to incorrect exponent and digit position.
        }
        sum = sum - 2; @@ // Arbitrary adjustment without justification; likely causes off-by-two error.
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // Accessing shuzi with possibly invalid index (e.g., beyond string length or pointing to '.').
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum); @@ // Exponent calculation is based on flawed sum, leading to wrong scientific notation.

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Only handles case where number is like "d.xxxx"; fails if more than one digit before decimal (e.g., "12.34")
        int sum = len - 2;

        printf("%se0", shuzi); @@ // Should output normalized form (single digit before decimal), not original string.
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Reusing loop variable 'i' inside loop that already uses 'i'; causes undefined behavior and overwrites outer loop variable.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Again reusing 'i' in nested scope; this corrupts the outer loop and leads to incorrect copying.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // If no '.' found, k remains 0, leading to exponent -1 which is wrong. Also, shuzi2 may be uninitialized if no decimal point exists.
    }

    return 0;
}