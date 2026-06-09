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
        in += 2; // @@ [This skips the '0' and the decimal point, but assumes input always starts with "0."; however, it fails to handle the case where after skipping zeros, we must place a decimal point after the first non-zero digit. The current logic prints all remaining digits without inserting a decimal point after the first significant digit, leading to missing '.' in scientific notation.]
        while (*(in++) == '0')
            cnt += 1;
        in -= 1;
        printf("%c", *(in)); // @@ [Only prints the first non-zero digit, but does not print a decimal point afterward, which is required by the problem specification for numbers with more than one significant digit.]
        in += 1;
        while (*(in) != '\0')
            printf("%c", *(in++)); // @@ [Prints the rest of the digits without a decimal point, resulting in an integer base instead of a decimal base like "9.123...", causing output like "9123456789012e-8" instead of "9.123456789012e-8".]
        printf("e-%d", cnt);
    }
    else
    {
        ptr = strchr(in, '.');
        whe = ptr - in + 1;
        printf("%c.", *(in++)); // @@ [Correctly prints first digit and decimal point, but note: if the number has only one digit before '.', this is fine. However, this branch doesn't account for trailing zeros or other edge cases—but the main bug is in the 'if' branch above.]
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