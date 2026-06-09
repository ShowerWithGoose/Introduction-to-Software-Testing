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
            printf("0"); // @@ [According to the problem, input always has digits before and after the decimal point, but this handles "0" which shouldn't occur. However, more critically, it doesn't output in scientific notation as required. Also, if input is "0.0...", the logic fails because it assumes non-zero digit exists.]
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
                    printf(".%c", s[i]); // @@ [This prints a decimal point followed by one digit, but if there are more digits after, they are printed without ensuring no trailing zeros. Also, the logic for when to print '.' is flawed—it prints '.' even if only one non-zero digit exists after leading zeros.]
                }
                else if (t == 1)
                    printf("%c", s[i]);
            }
            printf("e%d", 1 - len + cnt); // @@ [Exponent calculation is incorrect. For example, input "0.00123" should give exponent -3, but this computes 1 - 5 + 1 = -3 (coincidentally correct), but for "0.1", len=3, cnt=1 → 1-3+1=-1, which is wrong (should be -1? Actually "0.1" → "1e-1", so -1 is correct). However, if no non-zero digit is found (all zeros after decimal), this logic breaks—undefined behavior since cnt remains 0 and loop ends without printing base. Also, if input is "0.0", it prints nothing before 'e', which is invalid.]
            
        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); // @@ [Fails to convert integer inputs to scientific notation. For example, input "123" should output "1.23e2", but this prints "123", violating output format requirement that base must have only one significant digit.]
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