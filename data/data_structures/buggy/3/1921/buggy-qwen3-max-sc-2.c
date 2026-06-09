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
            printf("0"); @@ [The problem states that the input has digits before and after the decimal point, so "0" alone is not a valid input. However, more critically, the output format requires scientific notation; printing "0" violates the output specification. Also, this case should not occur per problem constraints, but if it does, it must still output in scientific notation like "0e0" or similar—but the bigger issue is handling of exponent calculation below.]
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
            printf("e%d", 1 - len + cnt); @@ [Incorrect exponent calculation. For example, input "0.00123" should yield "1.23e-3". Here, len=6, cnt becomes 1 at first non-zero ('1' at index 4), then cnt becomes 2. So exponent = 1 - 6 + 2 = -3, which accidentally works for this case. But if only one digit after leading zeros (e.g., "0.005"), then cnt=1, t remains 0, loop ends, and exponent = 1 - 5 + 1 = -3, but output is "5e-3" — which is correct per spec (single digit base without decimal). However, if there are more digits, e.g., "0.1", len=3, i=2: s[2]='1', cnt=0→1, then loop ends. t=0, so no decimal printed. Output: "1e-1" — correct. BUT: what if input is "0.10"? Problem says no trailing zeros, so maybe okay. However, the real bug is when the number is like "0.0001", len=6, i=2→'0', i=3→'0', i=4→'0', i=5→'1': cnt=1, loop ends, t=0 → prints "1e-4"? Exponent: 1 - 6 + 1 = -4 → correct. So why error? Wait—what if all digits after decimal are zero? But problem says all digits are significant, so no. However, another critical flaw: if the first non-zero is the last character, then t remains 0, so no decimal point is printed, which is correct (single digit). But the exponent formula is fragile. However, the main logical error is in the non-zero-leading case.]

        }
    }
    else 
    {
        for (;s[i] != '.' && i < len; i++)
            cnt++;

        if (i == len)
        {
            printf("%s", s); @@ [This prints the whole number as-is, but per spec, if it's an integer with more than one digit, it must be converted to scientific notation. E.g., input "123" should output "1.23e2", but this prints "123", which is wrong. Only single-digit integers can be printed without decimal and exponent "e0". So this branch fails for multi-digit integers.]
        }
        else
        {
            printf("%c.", s[0]);
            for(int j = 1; j < len; j++)
            {
                if (s[j] != '.')
                    printf("%c", s[j]);
            }
            printf("e%d", cnt-1); @@ [This part is mostly correct for numbers with decimal point and non-zero leading digit. E.g., "123.45" → cnt=3 (digits '1','2','3'), so exponent=2, output "1.2345e2" — correct. But note: what if input is "1.0"? Problem says no trailing zeros, so "1.0" won't appear. So this may be okay. The real error is in the integer case above.]
        }
    }

    return 0;
}