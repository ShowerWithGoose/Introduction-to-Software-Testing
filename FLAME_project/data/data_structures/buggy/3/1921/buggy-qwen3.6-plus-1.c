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
            printf("e%d", 1 - len + cnt); // @@ The exponent calculation is incorrect. For input "0.00000009123456789012", len=22. The first non-zero digit '9' is at index 9. The exponent should be -(9-1) = -8. The current formula uses `cnt` which counts the digits printed after the first significant digit. In the loop, `cnt` becomes 2 after printing the first two significant digits ('9' and '1'). So it calculates 1 - 22 + 2 = -19. The correct exponent for a number 0.00...0d... is -(position_of_d - 1). The position of the first non-zero digit `s[i]` is `i`. So the exponent should be `-(i-1)` or `1-i`. Since `i` is the loop variable, we need to track the index of the first non-zero digit.
            
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