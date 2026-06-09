#include <stdio.h>
#include <string.h>

int main()
{
    char s[110];
    scanf("%s", s);

    int i = 0, cnt = 0, t = 0, len = strlen(s);
    char sign;

    if (s[0] == '0')
    {
        if (s[1] == '\0')
            printf("0");
        else
        {
            for (i = 2; i < len; i++)
            {
                if (s[i] != '0' && cnt == 0)
                {
                    printf("%c", s[i]);
                    cnt = 1;
                }
                else if (cnt == 1)
                {
                    cnt++, t = 1;
                    printf(".%c", s[i]);
                }
                else if (t == 1)
                    printf("%c", s[i]);
            }
            printf("e%d", 1 - len + cnt); // @@ The exponent calculation is incorrect. For input "0.00...09...", the exponent should be -(number of zeros after decimal + 1). The current formula `1 - len + cnt` does not correctly account for the position of the first significant digit relative to the decimal point. Specifically, `cnt` here tracks the number of printed digits (which is wrong logic for exponent), and `len` includes the "0." prefix. The correct exponent for a number like 0.00...0d... is negative, specifically -(position of first non-zero digit after decimal). A simpler correct logic for the exponent when s[0]=='0' is: find the index `k` of the first non-zero digit after the decimal point. The exponent is `-(k - 1)`. In the loop, `i` is the index. When the first non-zero is found at `i`, the exponent is `-(i - 1)`. The variable `cnt` is being misused as a flag and counter for printing, not for exponent calculation.
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s);
        }
        else
        {
            printf("%c.", s[0]);
            for(int j = 1; j < len; j++)
            {
                if (s[j] != '.')
                    printf("%c", s[j]);
            }
            printf("e%d", cnt-1);
        }
    }

    return 0;
}