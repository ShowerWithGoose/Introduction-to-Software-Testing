#include <stdio.h>
int main()
{
    char in[200];
    scanf("%s", in);
    if (in[0] == '0' && in[1] == '.')
    {
        //<1
        int ct;
        for (ct = 2; in[ct] == '0'; ct++)
            ; // num of zeros+2
        printf("%c", in[ct]);
        printf("%c", '.'); // @@ [This always prints a decimal point even when there are no digits after the first non-zero digit, leading to incorrect format like "9." instead of "9" for single-digit mantissa. For input "0.9", it prints "9." followed by "9", resulting in "9.9".]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++)
        {
            printf("%c", in[j]); // @@ [This loop starts at index `ct`, which is the position of the first non-zero digit (e.g., '9' in "0.9"), so it prints that digit again after already printing it above, causing duplication: first '9' from `printf("%c", in[ct])`, then another '9' here.]
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [This prints the entire input as-is followed by "e0", which is wrong. For example, input "5.3" would output "5.3e0", but correct scientific notation should be "5.3e0" only if we keep one digit before decimal — however, per problem, base must have exactly one significant digit before decimal and no trailing zeros. But more critically, this branch doesn't normalize the number; it just appends e0. However, for inputs like "5.0", it's invalid per problem (no trailing zeros), so maybe acceptable? But still, this doesn't handle cases where there are more digits after decimal properly in terms of normalization. However, the immediate bug is in the first branch.]
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++)
        {
            if (q == ct2)
                continue;
            else
            {
                printf("%c", in[q]);
            }
        }
        printf("e%d", ct2-1);
    }
}