#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL) // @@ [Using gets() is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers]
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
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++); // @@ [The loop body is empty due to misplaced semicolon; 'num' counts digits before '.', but logic is flawed because 'num' is incremented after condition check, leading to off-by-one errors]
        
            b=num;
            if(s[num-1]=='0') // @@ [Accessing s[num-1] assumes at least one digit before '.', but input like "0.123" makes num=1, so s[0]=='0' is valid; however, logic for handling leading zeros after decimal is incorrect and doesn't account for cases where all digits after decimal are zero (though problem states no trailing zeros)]
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++) // @@ [This loop counts leading zeros after decimal point, but variable 'a' is not initialized properly in all paths and indexing is off: starts at num+1 which is first digit after '.', but then uses a+2 later which may go out of bounds]
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ [Incorrect index: after decimal, first non-zero digit is at position num+1+a, not a+2; this leads to wrong digit being printed or undefined behavior]
                if(a+2!=strlen(s)) // @@ [Wrong boundary check; should compare against actual position of last digit]
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++) // @@ [Incorrect starting index for fractional part; skips necessary digits or accesses beyond string length]
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ [Exponent calculation is incorrect; for "0.00123", exponent should be -3, but this prints -(number_of_leading_zeros + 1), which may be off]
            }
            else
            {
                printf("%c.",s[0]);
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
            printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}