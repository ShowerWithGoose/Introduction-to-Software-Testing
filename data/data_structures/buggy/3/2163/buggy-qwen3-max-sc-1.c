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
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Incorrect logic to find first non-zero after leading zeros; double counting 'sum' leads to wrong exponent and index.
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) { @@ // This loop reuses 'sum' incorrectly, causing double increment and wrong offset.
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2;
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // May access out-of-bounds if 'sum + 1 >= len'; also logic for extracting mantissa is flawed.
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

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Only handles case where number is like "d.xxxx"; fails if more than one digit before decimal (e.g., "12.3").
        int sum = len - 2;

        printf("%se0", shuzi);
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Reusing loop variable 'i' inside another loop causes undefined behavior and incorrect copying.
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Again reusing 'i' in nested scope corrupts outer loop and leads to incorrect array indexing.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // If no '.' found, 'k' remains 0, leading to exponent -1 which is wrong; also 'shuzi2' may be uninitialized.
    }

    return 0;
}