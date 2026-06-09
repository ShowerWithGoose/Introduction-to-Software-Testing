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
            
            printf("%c",s[a+2]); // @@ This indexing is incorrect. For input "0.001", num=1, a=2, s[a+2] = s[4] which is out of bounds or wrong character. It should output the first non-zero digit after the decimal.
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ This loop starts from a+3, which may skip characters or go out of bounds. The logic for printing the remaining digits after the first non-zero digit is flawed.
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ The exponent calculation is incorrect. For "0.001", a=2, exponent should be -3, but a+1=3, which is wrong.
            }
            else
            {
                printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1); // @@ For numbers like "10.0" (though trailing zeros are not allowed per spec), b-1 would be 1, but the exponent should be 1. However, this logic fails for numbers like "1.0" where b=1, b-1=0, which is correct. But for numbers with more than one digit before decimal, e.g., "12.34", b=2, b-1=1, but the exponent should be 1, so this is correct. However, the base output includes the decimal point even if the number is an integer after conversion, which violates the spec (should be integer if only one digit).

            }
        }
        else 
        {
            printf("%c.",s[0]); // @@ For integer inputs (no decimal point), this always adds a decimal point, but the spec says if the base is an integer, it should have no decimal point. For example, input "5" should output "5e0", not "5.e0".
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1); // @@ For integer input "5", strlen(s)-1 = 0, exponent is correct. But for "123", strlen(s)-1 = 2, exponent should be 2, which is correct. However, the base output is wrong due to the decimal point.
        }
    }
    return 0;
}