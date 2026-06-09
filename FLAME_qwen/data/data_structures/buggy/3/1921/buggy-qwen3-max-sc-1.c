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
            printf("0"); // @@ [The problem states that input has digits before and after the decimal point, but this handles "0" which shouldn't occur. However, more critically, when input is like "0.001", the exponent calculation is wrong. The exponent should be -(position of first non-zero after decimal), but current formula `1 - len + cnt` is incorrect.]
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
            printf("e%d", 1 - len + cnt); // @@ [Incorrect exponent calculation for numbers less than 1. For example, input "0.001" should output "1e-3", but this computes exponent as 1 - 4 + 1 = -2, which is wrong. Correct exponent is -(i - 1) where i is index of first non-zero digit after decimal.]
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); // @@ [Fails to convert integer inputs to scientific notation. For example, input "123" should output "1.23e2", but this just prints "123".]
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