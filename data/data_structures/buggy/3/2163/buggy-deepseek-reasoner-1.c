#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { // @@ Logical error: assumption that len-2 is a valid index and that the last two characters are specific. This condition is not general for all valid inputs (e.g., "0.001" has len=5, len-2=3 which is '0', but should not be treated as trailing zero since it's significant). Additionally, the base extracted (shuzi[len-1]) may not be the first non-zero digit.
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { // @@ Logical error: same issue with len-2; the condition may incorrectly classify numbers like "0.12" (len=4, len-2=2 which is '1', not '0', so enters this branch) but the subsequent loops fail to correctly compute the exponent and base for numbers with multiple zeros after decimal (e.g., "0.001" gives base "1." instead of "1").
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
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        // @@ Missing null terminator for shuzi2, which may cause undefined behavior when using printf with %s later (though not used here, but still a bug).
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum);

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') {
        int sum = len - 2;

        printf("%se0", shuzi); // @@ Logical error: sum is computed but never used; also the output should be the whole input string plus "e0", but for cases where the input has more than one digit after decimal, this is correct only if the input already has exactly one digit before decimal and no trailing zeros, which is fine. However, the problem requires that if the base is a decimal it must have exactly one digit after decimal? Actually the reference program prints all digits after decimal, so this is acceptable. No major error here.
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { // @@ Potential off-by-one: the loop condition i <= k means when i==k, shuzi2[i] = shuzi[i-1] which is correct (copying digits before decimal). However, after the loop, the subsequent loop copies digits after decimal starting from k+1. This seems correct.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) {
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); // @@ Missing null terminator for shuzi2; array may contain garbage after the last copied character, causing printf to print extra characters.
    }

    return 0;
}