#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { @@ // This condition assumes the second last character is '0', but input may not have trailing zeros; also fails when number has only one digit after decimal or no decimal at all.
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum);
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Incorrect logic to find first non-zero digit; double increment of 'sum' leads to wrong exponent and misaligned output.
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++;
        }

        for (int i = 0; i < len; i++) { @@ // This loop reuses 'i' incorrectly and overcounts 'sum'; also, it doesn't skip the decimal point properly.
            if (shuzi[i] != '0') {
                break;
            }
            sum++;
        }
        sum = sum - 2;
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // Potential out-of-bounds access if 'sum + 1 >= len'; also logic for extracting mantissa is flawed.
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

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Assumes that if first digit isn't '0', then second must be '.'; fails for numbers like "123.45".
        int sum = len - 2;

        printf("%se0", shuzi);
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Re-declares 'i' in inner scope, causing confusion; also copies digits incorrectly (should copy from index 1 to k-1).
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Again re-declares 'i'; this overwrites previously written parts of shuzi2 incorrectly.
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // If no '.' found, 'k' remains 0, leading to wrong exponent (e.g., -1); also shuzi2 may be uninitialized.
    }

    return 0;
}