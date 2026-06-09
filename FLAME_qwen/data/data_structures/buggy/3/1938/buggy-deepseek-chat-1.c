#include <stdio.h>
#include <math.h>
#include <string.h>
char s[110];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int i=0,flag=0;
    if(strchr(s,'.')==NULL)
    {
        for(i=len-1;i>=1;i--)
        {
            if(s[i]!='0')
            {
                flag=i;
                break;
            }
        }
        if(flag==0)
        {
            printf("%c",s[0]);
        }
        else
        {
            printf("%c.",s[0]);
            for(i=1;i<=flag;i++)
            {
                printf("%c",s[i]);
            }
        }
        printf("e%d",len-1); // @@ Error: For integer input without decimal point, the exponent should be len-1 only if the number has no trailing zeros. The reference program handles this differently; here the exponent calculation is incorrect for numbers like "100" where the significant digits are "1" and exponent should be 2, but this code outputs "1e2" which is correct for "100", but for "10" it outputs "1e1" which is also correct. However, the problem states that all digits are significant and there are no trailing zeros after decimal point, but for integers without decimal point, trailing zeros are significant? The problem says "all digits are significant (i.e., there are no trailing zeros after the decimal point)" - this applies only to numbers with decimal point. For integers like "100", the zeros are significant, so the output should be "1e2" which this code does. But the reference program does not handle integers without decimal point at all - it only handles numbers with decimal point. The test case input is empty, so this code may have issues with empty input or other edge cases. The main error is that the program does not handle the case when the input is a decimal number with leading zeros correctly, and the exponent calculation for the case s[0]=='0' is wrong.
        }
    }
    else
    {
        if(s[0]=='0')
        {
            for(i=0;i<len;i++)
            {
                if(s[i]!='0'&&s[i]!='.')
                {
                    flag++;
                }
                if(flag==2)
                {
                    printf(".");
                }
                if(flag!=0)
                {
                    printf("%c",s[i]);
                }
            }
            printf("e%d",2-len); // @@ Error: The exponent calculation for numbers like "0.001" is incorrect. The exponent should be -3, but 2-len gives 2-5=-3 which is correct for "0.001" (len=5). However, for "0.0001" (len=6), 2-6=-4 which is correct. But the logic for printing the base is flawed: it prints the first non-zero digit and then a dot after the second non-zero digit, which is wrong. The base should have exactly one digit before the decimal point and one digit after, but this code prints all non-zero digits and inserts a dot after the second one, which is incorrect.
        }
        else
        {
            for(i=0;i<len;i++)
            {
                if(s[i]=='.')
                {
                    flag=i;
                    break;
                }
            }
            printf("%c",s[0]);
            printf(".");
            for(i=1;i<len;i++)
            {
                if(s[i]!='.')
                printf("%c",s[i]);
            }
            printf("e%d",flag-1); // @@ Error: For numbers like "12.34", flag=2, exponent should be 1 (since 12.34 = 1.234e1), but flag-1=1 which is correct. However, for numbers like "1.234", flag=1, exponent should be 0, but flag-1=0 which is correct. The issue is that the base should have only one digit after the decimal point, but this code prints all digits after the decimal point, which violates the requirement that the base must have exactly one significant digit after the decimal point (no trailing zeros). For example, "1.23" should output "1.23e0" but the problem expects "1.23e0"? Actually the problem says "If it’s a decimal, it must have one significant digit before and after the decimal point" - this means the base should have exactly one digit before and one digit after the decimal point, so "1.23" should become "1.2e0"? No, that would lose precision. The problem statement is ambiguous: it says "one significant digit before and after the decimal point" but also says "all digits are significant". The reference program for numbers like "12.34" outputs "1.234e1" which has multiple digits after decimal point. So the requirement is that the base has one digit before the decimal point, and all significant digits after the decimal point (no trailing zeros). This code correctly prints all digits after the decimal point, so this part is actually correct. The main errors are in the handling of the s[0]=='0' case.
        }
    }
    return 0;
}