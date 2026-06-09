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
            printf("0"); @@ [The problem states that the input has digits before and after the decimal point, but this handles "0" alone, which is invalid per problem constraints. However, more critically, when the number starts with "0.", the exponent calculation is incorrect. For example, for "0.00123", it should output "1.23e-3", but the current logic computes exponent as 1 - len + cnt, which is wrong. Also, if all digits after decimal are zero (though problem says no trailing zeros), this may output nothing before 'e'.]
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
            printf("e%d", 1 - len + cnt); @@ [Exponent calculation is incorrect. For "0.00123" (len=6), first non-zero at i=4 ('1'), so exponent should be -(i-1) = -3. But 1 - 6 + 1 = -4, which is wrong. Correct exponent is -(i - 1).]
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); @@ [If input is an integer like "123", scientific notation should be "1.23e2", not "123". The problem requires one significant digit before decimal (or as integer only if single digit). So "123" must become "1.23e2", but this prints "123" as-is.]
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