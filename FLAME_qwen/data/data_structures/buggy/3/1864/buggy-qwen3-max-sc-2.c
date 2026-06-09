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
        printf("%c", '.'); // @@ [This prints a '.' even when there are no digits after the first non-zero digit, which may result in trailing decimal point or extra digits. Also, it prints the first non-zero digit twice: once before '.' and once again inside the loop starting at j=ct.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at j=ct, which includes the first non-zero digit again, causing duplication. Should start at j=ct+1. Also, input from scanf with %s won't contain '\n', so checking for '\n' is unnecessary.]
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
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Loop condition checks for '\n', but scanf with %s doesn't include newline. Also, this loop prints all digits including those after '.', but skips only the '.' itself. However, it may print trailing zeros if present, violating the "no trailing zeros" rule. Additionally, if the number has more than one digit before '.', the output base should have only one digit before decimal, which is correct, but the fractional part must not include trailing zeros — this code doesn't remove them.]
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