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
            
            printf("%c",s[a+2]); // @@ With a=0, this prints s[2], which is '9'. This part is technically correct for the digit, but the subsequent logic is flawed.
                if(a+2!=strlen(s)) // @@ For "0.9", strlen(s) is 3. a+2 is 2. 2 != 3 is true. So it enters this block to print the decimal part.
                {
                    printf("."); // @@ It prints a decimal point. This is incorrect because there are no more significant digits after '9' to form a decimal fraction like "9.xxx". The expected output is an integer "9" if there are no trailing digits.
                for(int i=a+3;i<strlen(s);i++) // @@ This loop starts at i=3. Since strlen(s) is 3, the loop doesn't execute. No further digits are printed.
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); // @@ Prints exponent. For "0.9", a=0, so it prints e-1. This part is correct.
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