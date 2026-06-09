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
        printf("%c", '.'); // @@ Error: This prints a decimal point even when the number has only one significant digit after the zeros (e.g., "0.5" should output "5e-1", not "5.5e-1"). The base should be an integer if there are no digits after the first non-zero digit.
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++)
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ Error: This prints the entire input including the decimal point, but the base should have only one digit before the decimal point. For example, "3.14" should output "3.14e0", which is correct, but "12.5" would not reach here. However, for inputs like "3.0" (though trailing zeros are not allowed per spec), this would incorrectly include the decimal point. The spec says if the base is an integer, no decimal point; but here it always prints the decimal point.
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