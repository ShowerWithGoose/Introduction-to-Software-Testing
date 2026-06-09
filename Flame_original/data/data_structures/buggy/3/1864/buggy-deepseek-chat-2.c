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
        printf("%c", '.'); // @@ Error: This prints a decimal point even when the number has only one significant digit after the zeros (e.g., "0.5" becomes "5." which is incorrect; the base should be "5" without a decimal point if there are no more digits)
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++)
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ Error: This prints the entire input including the decimal point, but the base should have only one digit before the decimal point (e.g., "1.23" should become "1.23e0", but this prints "1.23e0" which is correct only if the input has exactly one digit before the decimal; however, the problem requires the base to have one significant digit before the decimal, which is already the case here, so this is actually correct for this case)
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