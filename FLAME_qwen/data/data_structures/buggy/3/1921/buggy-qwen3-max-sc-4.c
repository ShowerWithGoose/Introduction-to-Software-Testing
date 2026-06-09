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
            printf("0"); @@ [The problem states that the input has digits before and after the decimal point, so "0" alone is not a valid input per problem constraints. However, more critically, this branch fails to output in scientific notation format as required. Also, if input is "0.0...", it should still produce scientific notation, but this outputs just "0", violating output format.]
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
            printf("e%d", 1 - len + cnt); @@ [Incorrect exponent calculation. For example, input "0.00123" should yield "1.23e-3", but this computes exponent as 1 - 5 + 1 = -3 only by coincidence. However, logic breaks when there are multiple leading zeros or no non-zero digit found. Also, if no non-zero digit is found (e.g., "0.000"), the loop ends without printing any base, leading to invalid output like "e...".]
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); @@ [Fails to convert integer inputs to scientific notation. For example, input "123" should output "1.23e2", but this prints "123", violating the output format which requires scientific notation with one significant digit before decimal (or as single digit if no fractional part).]
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