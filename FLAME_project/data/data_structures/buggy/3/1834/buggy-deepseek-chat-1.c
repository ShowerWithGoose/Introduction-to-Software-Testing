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
            
            printf("%c",s[a+2]); // @@ This line incorrectly assumes the first non-zero digit is always at index a+2. For input "0.9", num=1, a=0, so s[2]='9', but the output should be just "9" without a decimal point. The logic fails to handle cases where there are no trailing zeros after the first non-zero digit.
                if(a+2!=strlen(s)) // @@ This condition is incorrect. It checks if the index a+2 is not the end of the string, but for "0.9", a+2=2 and strlen(s)=3, so it prints a decimal point, but the expected output has no decimal point because there is only one significant digit after the decimal point.
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ The exponent calculation is wrong. For "0.9", a=0, so it prints "e-1", which is correct, but the base part is wrong.
            }
            else
            {
                printf("%c.",s[0]); // @@ This always prints a decimal point after the first digit, but for numbers like "0.9" (which falls into the if branch, not else), this is not the issue. However, for numbers with more than one digit before the decimal, this may incorrectly add a decimal point when the base should be an integer.
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1);

            }
        }
        else 
        {
            printf("%c.",s[0]); // @@ For integer inputs, this always adds a decimal point, but the problem states that if the base is an integer, it should have no decimal point.
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}