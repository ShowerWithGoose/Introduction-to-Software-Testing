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
            printf("0"); @@ [The problem states that the input has digits before and after the decimal point, so "0" alone is not a valid input. However, more critically, this branch prints "0" without scientific notation, violating output format. Also, the exponent calculation later is incorrect.]
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
            printf("e%d", 1 - len + cnt); @@ [Exponent calculation is wrong. For example, input "0.00123" should yield exponent -3, but this formula gives 1 - 5 + 1 = -3 (coincidentally correct for this case), but fails for others like "0.1" (len=3, cnt=1 → 1-3+1=-1, which is correct), yet logic doesn't handle cases where no non-zero digit is found. Also, if all digits after decimal are zero (though problem says no trailing zeros, but still), it may print nothing before 'e'.]
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); @@ [This prints the whole number as-is when there's no decimal point, but per problem, output must be in scientific notation. For example, input "123" should output "1.23e2", not "123".]
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