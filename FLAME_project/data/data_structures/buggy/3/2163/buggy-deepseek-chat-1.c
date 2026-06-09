#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { // @@ This condition incorrectly assumes the second-to-last character is '0' for all cases like "0.9", where len-2 is '.' not '0'. It fails to handle general cases.
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { // @@ This condition also incorrectly uses len-2, which for "0.9" is '.' (not '0'), so it enters this branch but the logic for counting leading zeros is flawed (double counting sum) and produces wrong output.
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) { // @@ This second loop is redundant and incorrectly increments sum again, causing sum to be too large.
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
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum);

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') {
        int sum = len - 2;

        printf("%se0", shuzi); // @@ This prints the original string including the decimal point, but for numbers like "1.0" (though not in test), it should output "1e0". For "0.9" this branch is not entered, but the logic is still incorrect for valid cases.
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

        printf("%se%d", shuzi2, k - 1); // @@ shuzi2 is not null-terminated and may contain garbage; also the exponent calculation k-1 is incorrect for numbers like "12.34" (should be 1, not k-1).
    }

    return 0;
}