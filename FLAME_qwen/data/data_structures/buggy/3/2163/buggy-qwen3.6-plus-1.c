#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { // @@ Incorrect condition: assumes only one non-zero digit at the end, fails for numbers like 0.105
        int sum = len - 2; // @@ Exponent calculation is flawed and depends on the incorrect condition above
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { // @@ Condition is logically flawed and overlaps poorly with the previous case
        int sum = 0;
        for (int i = 0; i < len; i++) { // @@ Logic to find the first non-zero digit is incorrect; sum is misused
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) { // @@ Second loop incorrectly increments sum again, leading to wrong index calculation
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2; // @@ Arbitrary adjustment does not correctly compute the exponent or array index
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; // @@ Uses incorrectly calculated sum, likely causing out-of-bounds access or selecting the wrong digit
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

    else if (shuzi[0] != '0' && shuzi[1] == '.') {
        int sum = len - 2;

        printf("%se0", shuzi);
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) {
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) {
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); // @@ shuzi2 is not null-terminated, causing undefined behavior when printed with %s
    }

    return 0;
}