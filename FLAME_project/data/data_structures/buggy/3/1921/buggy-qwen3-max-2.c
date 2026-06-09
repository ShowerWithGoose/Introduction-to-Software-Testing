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
            printf("e%d", 1 - len + cnt); // @@ [The exponent calculation is incorrect. It should be based on the position of the first non-zero digit after the decimal point, not derived from total length and cnt in this way. For input "0.00000009123456789012", the first non-zero digit '9' is at index 8 (0-based), so exponent should be -(8-1) = -7? Wait: actually, 0.00000009 = 9e-8, so exponent is -8. The correct exponent is -(position_after_decimal_of_first_nonzero). Since '9' is the 8th digit after decimal (positions 2 to 9: s[2]='0', ..., s[9]='9'), so exponent = -8. Current formula 1 - len + cnt gives 1 - 22 + 2 = -19, which is wrong.]
            
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