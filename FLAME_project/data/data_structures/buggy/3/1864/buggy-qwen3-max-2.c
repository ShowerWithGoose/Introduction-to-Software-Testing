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
        printf("%c", '.'); // @@ [Unconditionally prints a decimal point even when there are no digits after the first non-zero digit, leading to trailing decimal point or extra digits. For input "0.9", it prints "9." followed by all digits from position ct onward, which includes '9' again, resulting in "9.9".]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++)
        {
            printf("%c", in[j]); // @@ [This loop starts at index `ct`, which is the first non-zero digit (e.g., '9' in "0.9"), so it prints that digit again after already printing it before the decimal point, causing duplication.]
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [Does not convert to proper scientific notation. For example, input "5.67" should become "5.67e0", but according to problem requirements, if there's only one digit before decimal and it's non-zero, it's acceptable—but this branch fails for numbers like "12.34" because it doesn't handle multi-digit integer parts correctly. However, for this specific test case "0.9", this branch isn't triggered. The main error is in the first branch.]
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