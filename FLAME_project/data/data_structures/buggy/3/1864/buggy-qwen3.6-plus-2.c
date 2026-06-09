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
        // @@ The problem states that if the base is an integer (only one significant digit), it should not have a decimal point. Here, for input "0.9", ct becomes 2, in[ct] is '9'. The code prints '9', then '.', then enters the loop. The loop starts at j=ct (which is 2), so it prints in[2] ('9') again. This results in "9.9". Furthermore, even if the loop didn't duplicate the digit, printing '.' after a single digit violates the rule "If it’s an integer, it contains only one significant digit without a decimal point". We need to check if there are any non-zero digits after the first significant digit to decide whether to print the decimal point and subsequent digits.
        printf("%c", '.');
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++)
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in);
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