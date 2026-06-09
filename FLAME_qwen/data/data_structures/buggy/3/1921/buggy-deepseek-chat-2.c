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
            printf("e%d", 1 - len + cnt); // @@ Error: The exponent calculation is incorrect. For numbers like "0.001", the exponent should be negative and based on the position of the first non-zero digit, but this formula does not correctly compute it. For example, with "0.001", len=5, cnt becomes 2 after the loop, so 1-5+2 = -2, but the correct exponent is -3.
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); // @@ Error: When the input is an integer with no decimal point, the output should be in scientific notation (e.g., "123" should become "1.23e2"), but this prints the original string without conversion.
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