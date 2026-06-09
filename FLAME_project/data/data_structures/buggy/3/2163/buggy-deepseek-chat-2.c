#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { // @@ This condition is incorrect for general cases; it assumes the last two characters are '0' and '.', but for input like "0.9", len-2 is the index of '9', not '0'. This branch is not taken for "0.9", but the logic is flawed.
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { // @@ For input "0.9", this branch is entered. However, the loop logic for calculating sum is incorrect: it counts zeros before the decimal point and then adds more zeros incorrectly, leading to sum = 0 (since there are no zeros after the decimal point except the one before). Then shuzi2 is built starting from shuzi[1] which is '.', causing the output "9.e-1" instead of "9e-1".
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2;
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1];
        shuzi2[1] = '.'; // @@ This always adds a decimal point, but for input "0.9", the output should be "9e-1" (no decimal point). The program incorrectly inserts a '.'.
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

        printf("%se%d", shuzi2, k - 1);
    }

    return 0;
}