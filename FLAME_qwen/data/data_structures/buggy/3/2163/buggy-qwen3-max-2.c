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
        printf("%ce-%d", shuzi[len - 1], sum); @@ // Incorrectly uses shuzi[len - 1] as significant digit; should find first non-zero after decimal, not assume last char is significant.
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Assumes there are at least two characters before end; fails for inputs like "0.1" (len=3, len-2=1 -> '.'), leading to incorrect logic.
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++; @@ // This loop counts positions until first non-zero/non-dot, but sum is incremented even when breaking, causing off-by-one.
        }

        for (int i = 0; i < len; i++) { @@ // This loop is redundant and incorrect; it again increments sum for leading zeros, double-counting.
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2; @@ // Arbitrary adjustment without clear justification; likely leads to wrong exponent.
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // May access out-of-bounds if sum+1 >= len; also logic for locating first significant digit is flawed.
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum);

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Only handles case where number is like "d.xxxx"; fails for numbers with more than one digit before decimal (e.g., "12.3").
        int sum = len - 2;

        printf("%se0", shuzi); @@ // Should output in normalized scientific notation (e.g., "1.23e1"), not original form with e0.
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Reuses loop variable 'i' inside loop that already uses 'i'; causes undefined behavior due to variable shadowing and incorrect indexing.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Same issue: redeclaring 'i' in inner scope leads to unpredictable loop behavior.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // If no '.' found, k remains 0, leading to exponent -1 and uninitialized shuzi2 content; also shuzi2 may not be null-terminated, causing undefined output.
    }

    return 0;
}