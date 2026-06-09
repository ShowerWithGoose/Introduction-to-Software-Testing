#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL)
    {
        int num=0,isok=0;
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
            isok=1;
            }
        }
        if(isok)
        {
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++);
        
            b=num;
            if(s[num-1]=='0') // @@ This condition incorrectly checks if the digit before the decimal point is '0', but the logic for handling numbers like "0.xxx" is flawed. It assumes the first digit before the decimal is '0' and then tries to skip leading zeros after the decimal, but the indexing and output logic are incorrect.
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ This indexing is incorrect. For input "0.001", num=1, a counts zeros after decimal (2 zeros), then s[a+2] = s[4] which is '1', but the output should be "1e-3". The logic fails for cases like "0.0" or when there are no zeros after decimal.
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ The exponent calculation is wrong. For "0.001", a=2, so exponent is a+1=3, which is correct, but for "0.1", a=0, exponent becomes 1, but correct exponent should be -1. The logic does not handle the case where the first digit after decimal is non-zero.
            }
            else
            {
                printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1); // @@ For numbers like "10.5", b=2, exponent is 1, correct. But for "1.5", b=1, exponent is 0, correct. However, this branch incorrectly handles numbers where the first digit before decimal is non-zero but there is only one digit before decimal (e.g., "1.5" should output "1.5e0" but this outputs "1.5e0" correctly). The issue is that this branch is also used for numbers like "12.5" where the first digit is non-zero but there are multiple digits before decimal, which is correct. However, the condition `if(s[num-1]=='0')` is meant to handle the case where the first digit is '0', but it fails for numbers like "0.5" because s[num-1] is '0', so it goes into the if branch, but the logic there is flawed.
            }
        }
        else 
        {
            printf("%c.",s[0]); // @@ For integer input without decimal point, this always adds a decimal point after the first digit, which is incorrect. For example, input "123" should output "1.23e2", but this outputs "1.23.e2" (extra dot) or "1.23e2" if the loop prints correctly, but the decimal point is added unconditionally, which is wrong. The correct output for integer "123" should be "1.23e2", but this code prints "1.23e2" (with a dot after first digit) which is actually correct for scientific notation of an integer? Wait, the problem says base can be integer or decimal. For integer input like "123", the scientific notation should be "1.23e2" (decimal base) or "123e0"? The problem says: "If it’s an integer, it contains only one significant digit without a decimal point." So for "123", the correct output should be "1.23e2" (decimal base) or "123e0"? Actually, the problem says the base is either a decimal or an integer. For "123", the scientific notation is "1.23e2" (decimal base) or "123e0" (integer base)? The reference program outputs "1.23e2" for "123". So this branch is actually correct for integer input? But the problem says "If it’s an integer, it contains only one significant digit without a decimal point." That means for "123", the base should be "1.23" (decimal) or "123" (integer)? The reference program outputs "1.23e2" for "123", so it treats it as decimal base. So this branch is correct for integer input? Wait, the reference program does not have a separate branch for integer input; it handles all inputs with a decimal point. For input without decimal point, the reference program would not work because it assumes there is a decimal point. So this code's else branch is an attempt to handle integer input, but it incorrectly adds a decimal point after the first digit, which is actually correct for scientific notation (e.g., "123" -> "1.23e2"). However, the problem expects that if the input has no decimal point, it should be treated as an integer? Actually, the problem says input has digits before and after the decimal point, so input always has a decimal point. So this else branch is unnecessary and incorrect because the input always contains a decimal point. But the test case might include integer input? The problem description says "The input data contains no sign, has digits before and after the decimal point", so there is always a decimal point. So this else branch is dead code but could cause issues if input is malformed.
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}