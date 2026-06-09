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
            if(s[num-1]=='0') // @@ The condition checks if the digit immediately before the decimal point is '0'. For input "0.9", s[0] is '0', so this branch is taken. However, the logic inside assumes there are leading zeros after the decimal point (like 0.009), which is incorrect for 0.9.
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++) // @@ This loop counts zeros after the decimal point. For "0.9", s[2] is '9', so the loop doesn't run, and 'a' remains 0.
                {
                    a++;
                }
            
            printf("%c",s[a+2]); // @@ With a=0, this prints s[2], which is '9'. This part is technically correct for the digit, but the subsequent logic fails.
                if(a+2!=strlen(s)) // @@ a=0, strlen("0.9")=3. 0+2 != 3 is true. So it enters the block to print the decimal point and remaining digits.
                {
                    printf("."); // @@ It prints a decimal point. For "0.9", the expected output is "9e-1" (integer base), not "9." or "9.something". The problem states: "If it’s an integer, it contains only one significant digit without a decimal point." Since there are no digits after the '9' in the significand, it should be treated as an integer base.
                for(int i=a+3;i<strlen(s);i++) // @@ This loop tries to print digits after the first significant digit. For "0.9", i starts at 3, which is strlen(s), so the loop doesn't run. But the decimal point was already printed.
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ Prints e-1. The output becomes "9.e-1". The error is the trailing decimal point when there are no fractional digits in the significand.
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