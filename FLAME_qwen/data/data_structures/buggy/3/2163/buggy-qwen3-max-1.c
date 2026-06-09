#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { @@ // Incorrect condition: assumes second last char is '0' to detect trailing zero, but input has no trailing zeros after decimal per problem statement; also fails when number is like "0.1"
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum); @@ // Wrong: uses last char as significant digit, but should find first non-zero after decimal; also sum calculation is incorrect
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ // Flawed logic: this branch tries to handle numbers like "0.00123", but the double loop for 'sum' is incorrect and overcounts
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++; @@ // This loop counts positions until first non-zero (excluding '.'), but then another loop adds more, leading to wrong exponent
        }

        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0') {
                break;
            }
            sum++; @@ // This double-counts leading zeros; logic is fundamentally broken
        }
        sum = sum - 2; @@ // Arbitrary adjustment; not based on correct exponent calculation
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ // May access out-of-bounds if sum+1 >= len; also incorrect indexing for first significant digit
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum); @@ // Exponent is incorrectly computed

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ // Only handles single-digit before decimal (e.g., "5.123"), but misses cases like "12.34" which should go to else branch; however, condition is too narrow and doesn't cover all valid inputs
        int sum = len - 2;

        printf("%se0", shuzi); @@ // Correct for numbers like "5.123", but output includes full original string instead of normalized form (should be "5.123e0", which matches, but problem requires only one digit before decimal — this is okay only if input already has one digit before decimal)
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ // Variable 'i' is redeclared in inner loop, causing shadowing and undefined behavior; also logic shifts digits incorrectly
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ // Again reuses 'i' in nested scope; after previous loop, outer 'i' is unchanged, so this may not run or behave unpredictably
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ // If no '.' found, k remains 0, leading to exponent -1 which is wrong; also shuzi2 may be uninitialized if no decimal point exists (though problem states input has decimal point)
    }

    return 0;
}