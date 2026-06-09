#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { @@ // Incorrect condition: assumes last two characters are '0' and something, but doesn't locate decimal point; fails for inputs like "0.001"
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum); @@ // Wrong digit selection: uses last character as significant digit, which may be zero or not the first non-zero after decimal
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Flawed logic: uses arbitrary index len-2 to check for trailing zero; doesn't correctly find first non-zero digit after decimal
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++; @@ // This loop counts leading zeros including '.', but then another loop below also increments sum incorrectly
        }

        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0') {
                break;
            }
            sum++; @@ // Double counting of leading zeros; sum becomes too large
        }
        sum = sum - 2; @@ // Arbitrary adjustment; not based on actual position of first non-zero digit
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // May access out-of-bounds if sum+1 >= len; also wrong offset due to incorrect sum
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum); @@ // Exponent is incorrect due to wrong calculation of sum

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Only handles case where number is like "d.xxxx"; fails if more than one digit before decimal (e.g., "12.34")
        int sum = len - 2;

        printf("%se0", shuzi); @@ // Should output in normalized scientific notation (e.g., "1.234e1"), not original form with e0
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Variable 'i' redeclared in inner scope; causes undefined behavior and overwrites outer loop variable
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Same issue: redeclaration of 'i' inside loop that already uses 'i'
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // shuzi2 may not be null-terminated; using %s on non-null-terminated array leads to undefined behavior
    }

    return 0;
}