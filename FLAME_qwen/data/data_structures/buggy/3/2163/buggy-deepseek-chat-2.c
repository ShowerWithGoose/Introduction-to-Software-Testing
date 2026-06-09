#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { // @@ The condition is incorrect; it assumes the last two characters are '0' and the decimal point, but the input format may vary. Also, the logic for handling this case is flawed and does not correctly convert to scientific notation.
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum); // @@ This output is incorrect; it only prints the last digit and an exponent, not the proper scientific notation.
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { // @@ The condition is ambiguous and does not correctly identify numbers less than 1. The logic for calculating 'sum' is redundant and incorrect.
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) { // @@ This loop is redundant and incorrectly increments sum again, leading to an incorrect exponent.
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2; // @@ The calculation of sum is incorrect; it does not properly count the number of leading zeros after the decimal point.
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; // @@ Indexing is incorrect; sum+1 may be out of bounds or point to the wrong character.
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum); // @@ The exponent sum is incorrectly calculated.

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { // @@ This condition only handles numbers with one digit before the decimal point, but the output "e0" is incorrect for numbers like 1.0 (should be 1e0, but the input has no trailing zeros). Also, it does not handle the case where the number is an integer (no decimal point).
        int sum = len - 2; // @@ Variable sum is unused.

        printf("%se0", shuzi); // @@ This prints the original string with "e0", which is incorrect for numbers like 12.34 (should be 1.234e1).
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { // @@ Variable i is reused, shadowing the outer loop variable, causing undefined behavior.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { // @@ Variable i is reused again, and the index for shuzi2 is incorrect; it should start from k+1, but the loop overwrites previous entries.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); // @@ shuzi2 is not null-terminated, and k may be uninitialized if no decimal point is found (e.g., integer input). Also, the exponent calculation k-1 is incorrect for numbers like 0.001 (should be negative).
    }

    return 0;
}