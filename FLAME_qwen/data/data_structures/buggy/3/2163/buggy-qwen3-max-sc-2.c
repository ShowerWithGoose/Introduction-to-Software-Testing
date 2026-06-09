#include <stdio.h>
#include <string.h>

int main() {
    char shuzi[1001];
    char shuzi2[1001];
    scanf("%s", shuzi);
    int len = strlen(shuzi);
    int k = 0;


    if (shuzi[0] == '0' && shuzi[len - 2] == '0') { @@ [This condition assumes the second last character is '0', but it doesn't check if there's a decimal point or handle general cases of leading zeros correctly. Also, accessing shuzi[len-2] is unsafe when len < 2.]
        int sum = len - 2;
        printf("%ce-%d", shuzi[len - 1], sum); @@ [This prints the last digit as the significant digit, which is incorrect if there are non-zero digits before it. Also, if input is "0.0", len=3, then shuzi[len-1]='0', which violates the requirement that significant digits are non-zero.]
    }

    else if (shuzi[0] == '0' && shuzi[len - 2] != '0') { @@ [Again, assumes len >= 2 and that the structure is always "0.xxx", but doesn't locate the decimal point. The logic for finding first non-zero digit is flawed due to double increment of 'sum'.]
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0' && shuzi[i] != '.') {
                break;
            }
            sum++; @@ [This counts positions including '.', but then another loop below also increments sum, leading to overcounting.]
        }

        for (int i = 0; i < len; i++) {
            if (shuzi[i] != '0') {
                break;
            }
            sum++; @@ [This double-counts leading zeros, causing incorrect exponent calculation.]
        }
        sum = sum - 2; @@ [Arbitrary adjustment without clear justification; likely incorrect.]
        int xin = 2;
        shuzi2[0] = shuzi[sum + 1]; @@ [May access out-of-bounds if sum+1 >= len. Also, doesn't skip the decimal point properly.]
        shuzi2[1] = '.';
        for (int i = sum + 2; i < len; i++) {
            shuzi2[xin] = shuzi[i];
            xin++;
        }
        for (int i = 0; i < xin; i++) {
            printf("%c", shuzi2[i]);
        }
        printf("e-%d", sum); @@ [Exponent is based on flawed 'sum', so likely wrong.]

    }

    else if (shuzi[0] != '0' && shuzi[1] == '.') { @@ [Assumes number has exactly one digit before decimal (like "5.123"), but fails if input is "12.34" (two digits before '.'). Also, doesn't verify that len > 1 before accessing shuzi[1].]
        int sum = len - 2;

        printf("%se0", shuzi); @@ [Correct only if input already has one non-zero digit before '.', but problem requires scientific notation even in this case to have normalized form (which it already is), so outputting original string is acceptable only if it matches format—but "5.123e0" is expected, not "5.123". However, per problem, if already normalized, e0 is correct. But this branch misses cases like "10.0" which should become "1.0e1".]
    }


    else {
        for (int i = 0; i < len; i++) {
            if (shuzi[i] == '.') {
                k = i;
                shuzi2[0] = shuzi[0];
                shuzi2[1] = '.';
                for (int i = 2; i <= k; i++) { @@ [Reusing loop variable 'i' inside a loop that already uses 'i' causes undefined behavior and incorrect copying. The inner 'i' shadows outer, and after loop, outer 'i' is corrupted.]
                    shuzi2[i] = shuzi[i - 1];
                }
                for (int i = k + 1; i < len; i++) { @@ [Again redefines 'i', compounding the error.]
                    shuzi2[i] = shuzi[i];
                }
            }
        }

        printf("%se%d", shuzi2, k - 1); @@ [If no '.' was found, 'k' remains 0, leading to exponent -1, which is wrong. Also, shuzi2 may be uninitialized if no '.' exists. Additionally, the copied string includes all digits before '.' shifted incorrectly.]
    }

    return 0;
}