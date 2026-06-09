#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { // @@ The condition is incorrect; it assumes the last two characters are always "0" and the decimal point, but the input may have different lengths and positions. Also, it does not handle cases where the number is like "0.001" correctly.
        int sum = len - 2; // @@ This calculation is wrong; it assumes the exponent is based on the length minus 2, but the exponent should be the number of zeros after the decimal point before the first non-zero digit.
        printf("%ce-%d", shuzi[len - 1], sum); // @@ This prints only the last character as the base, which is incorrect; the base should be the first non-zero digit.
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { // @@ The condition is flawed; it checks the second-to-last character, which may not be the decimal point or relevant. It does not correctly identify numbers like "0.123".
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
        sum = sum - 2; // @@ This adjustment is arbitrary and does not correctly compute the exponent.
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; // @@ This indexing is incorrect; it assumes the first non-zero digit is at position sum+1, but sum is miscalculated.
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

    else if (shuzi[0] != '0' && shuzi[1] == '.') { // @@ This condition only handles numbers with exactly one digit before the decimal point, but it does not correctly output the exponent (should be 0, but the code prints "e0" via the printf below, which is correct for this case, but the logic is incomplete for other cases).
        int sum = len - 2; // @@ This variable is unused, indicating dead code.

        printf("%se0", shuzi); // @@ This prints the entire input string as the base, which is incorrect; the base should have only one digit before the decimal point (e.g., "1.23" for "1.23" should become "1.23e0", but this prints "1.23e0" correctly only if the input is already in that form, but it fails for inputs like "12.34").
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { // @@ The loop variable i shadows the outer i, causing confusion and potential errors. Also, the indexing is off: shuzi2[2] should get shuzi[1], but the loop starts at i=2 and uses shuzi[i-1], which is correct, but the outer i is overwritten.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { // @@ Again, i shadows the outer i, and the indexing for shuzi2 is incorrect; it should continue from the previous index, but it starts at k+1, which may overwrite or leave gaps.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); // @@ shuzi2 is not null-terminated, and the exponent calculation k-1 is correct only if the decimal point is at position k, but the loop may not have set k correctly if the decimal point is not found.
    }

    return 0;
}