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
        printf("%c", '.'); // @@ The problem states that if the base is an integer (only one significant digit), it should not have a decimal point. For input "0.9", the significant part is just "9". The code unconditionally prints a decimal point, resulting in "9." instead of "9". Furthermore, the subsequent loop prints remaining digits, but for "0.9", there are no more digits, so it outputs "9.". If there were more digits like "0.0901", it would print "9.01", which is correct for decimal base, but for single digit like "9", it should be integer format. Specifically for "0.9", expected is "9e-1", got "9.e-1" or similar depending on loop. Actually, looking at the buggy output "9.9e-1", it seems the loop below is printing the current digit again or something. Let's trace "0.9". ct starts at 2. in[2] is '9'. Loop `for (ct = 2; in[ct] == '0'; ct++)` does not execute because in[2]!='0'. So ct=2. Print in[2] -> '9'. Print '.'. Loop `for (int j = ct; ...)` starts at j=2. in[2] is '9'. Prints '9'. So output so far "9.9". Then exponent. This explains the "9.9" part. The error is printing the decimal point and then re-printing the first significant digit in the loop.
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