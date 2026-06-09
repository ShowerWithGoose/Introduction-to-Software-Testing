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
            if(s[num-1]=='0')
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ This line incorrectly calculates the index for the first significant digit after leading zeros. For input "0.9", num=1, a=0, so s[a+2]=s[2]='9', but the logic fails for cases like "0.001" where a=2 and s[4] would be needed. Also, it doesn't handle the case where the number is just "0.0" correctly.
                if(a+2!=strlen(s)) // @@ This condition is flawed; it should check if there are more digits after the first significant digit, not compare index to string length.
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ This loop starts from the wrong index, skipping the first significant digit and potentially including the decimal point.
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ The exponent calculation is incorrect. For "0.9", a=0, so exponent is -1, which is correct, but for "0.001", a=2, exponent should be -3, but this gives -3, which is correct. However, the logic for determining 'a' is flawed.
            }
            else
            {
                printf("%c.",s[0]); // @@ This always prints a decimal point after the first digit, but for numbers like "1.0" (which shouldn't appear per spec) or when the base should be an integer (e.g., "9" from "0.9" should be "9e-1", not "9.e-1"), this adds an unnecessary decimal point.
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1); // @@ The exponent calculation for non-zero leading digit case is correct, but the base formatting is wrong (extra decimal point).

            }
        }
        else 
        {
            printf("%c.",s[0]); // @@ For integer inputs (no decimal point), this always adds a decimal point, but the spec says if the base is an integer, it should have no decimal point.
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1); // @@ The exponent calculation for integers is correct.
        }
    }
    return 0;
}