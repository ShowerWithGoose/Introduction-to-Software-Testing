#include <stdio.h>
#include <string.h>
char in[101];
char *ptr;
int whe;
void fa(char in[])
{
    if (*(in) == '0')
    {
        int cnt = 1;
        in += 2; // @@ [If the input is "0.0...", this skips the '.' correctly, but if the input has no decimal point (which shouldn't happen per problem statement), this leads to undefined behavior. However, the real issue is that if the number after "0." has no non-zero digit (e.g., "0.0"), the loop runs past the string end, causing undefined behavior. Also, the logic for counting exponent is off by one in some cases.]
        while (*(in++) == '0') // @@ [This increments `in` before checking termination; if the string ends with zeros, it may read beyond '\0'. Also, if all digits after "0." are zero (though problem says no trailing zeros), this loops indefinitely or crashes.]
            cnt += 1;
        in -= 1; // @@ [This attempts to undo the final increment from the while loop, but if the loop exited because *(in) != '0', then in already points to the first non-zero digit. However, due to post-increment in condition, it's actually one past, so this correction is needed—but only if the loop ran at least once. If the first digit after "0." is non-zero, the loop doesn't run, and `in` was incremented once in `in += 2`, then again in `while (*(in++) ...` condition check even if body doesn't execute—so logic is flawed.]
        printf("%c", *(in));
        in += 1;
        while (*(in) != '\0')
            printf("%c", *(in++));
        printf("e-%d", cnt); // @@ [Exponent calculation is incorrect. For "0.001", expected exponent is -3, but cnt becomes 3 (starting at 1, then two more zeros), so prints e-3 which is correct. But for "0.1", cnt=1, prints e-1 which is correct. However, the initial `in += 2` assumes there's always a decimal point after "0", which is true per problem, but the loop logic is fragile and may access out-of-bound memory if input doesn't conform (though problem says it does). The main error is potential buffer overread in while loop.]
    }
    else
    {
        ptr = strchr(in, '.'); // @@ [If there's no decimal point (e.g., integer input like "123"), strchr returns NULL, leading to segmentation fault when computing `whe = ptr - in + 1`. The problem states input has digits before and after decimal point, so this may not occur, but the code doesn't validate. However, per problem description: "has digits before and after the decimal point", so '.' must exist. So this might be safe, but still risky.]
        whe = ptr - in + 1; // @@ [For input "12.34", ptr - in = 2, so whe = 3. Then exponent printed is whe - 2 = 1, which is correct (1.234e1). So logic seems okay if '.' exists.]
        printf("%c.", *(in++));
        while (*(in) != '\0')
        {
            if (*(in) == '.')
                in += 1;
            else
                printf("%c", *(in++));
        }
        printf("e%d", whe - 2);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%s", in);
    fa(in);
    return 0;
}