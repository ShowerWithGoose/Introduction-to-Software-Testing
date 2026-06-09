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
        printf("%ce-%d", shuzi[len - 1], sum); @@ // Incorrectly uses shuzi[len - 1] as significant digit; should find first non-zero after decimal, not assume it's at end.
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Assumes there are at least two characters before end; fails for inputs like "0.1"
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++; @@ // This loop counts leading zeros including '.', but logic is flawed because '.' is not a digit and shouldn't be counted in position calculation.
        }

        for (int i = 0; i < len; i++) { @@ // This loop duplicates counting logic and overwrites 'sum' incorrectly.
            if (shuzi[i] != '0') {
                break;
            }
            sum++; @@ // Double counting leads to wrong exponent.
        }
        sum = sum - 2; @@ // Arbitrary adjustment without justification; likely incorrect.
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // May access out-of-bounds if sum+1 >= len.
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum); @@ // Exponent calculation is based on flawed 'sum'.
    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Only handles case where number is like "d.xxxx"; fails for numbers with more than one digit before decimal like "12.3"
        int sum = len - 2;

        printf("%se0", shuzi); @@ // Should output in normalized scientific notation (e.g., "1.23e1"), not original form.
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Reuses loop variable 'i' inside loop that already uses 'i'; causes undefined behavior and incorrect copying.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Again redefines 'i' in inner scope; outer 'i' becomes corrupted.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // If no '.' found, 'k' remains 0, leading to wrong exponent; also shuzi2 may be uninitialized or incomplete.
    }

    return 0;
}