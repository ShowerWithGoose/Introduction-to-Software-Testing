#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it reads the entire line including the newline, but the logic below assumes the last character is part of the number. However, the main error is elsewhere.]
    int len=strlen(s);
    
    int num1=0;
    int i=0;
    while(s[i]!='.')
    {
        i++;
        num1++;
    }
    if(num1>1)
    {
        printf("%c.",s[0]);
        for(i=1;i<len-1;i++) // @@ [This loop stops at len-2 (since condition is i < len-1), so it skips the last character of the input string. The input "87899.9999999999000999" has significant digits at the end that are being cut off, causing the output to miss the final '9'.]
        {
            if(s[i]!='.')
            printf("%c",s[i]);
        }
        printf("e%d",num1-1);
    }
    else if(num1=1&&s[0]!='0') // @@ [This uses assignment '=' instead of comparison '==', which always sets num1 to 1 and evaluates to true if s[0]!='0'. This causes incorrect control flow for numbers with more than one digit before the decimal point, but in this test case it's not triggered because num1>1.]
    {
        for(i=0;i<len;i++)
        {
            printf("%c",s[i]);
        }
        printf("e0");
    }
    else
    {
        int num2=0;
        i=2;
        while(1)
        {
            if(s[i]!='0') 
            break;
            i++;
            num2++;
        }
        if(i==len-1)
        {
            printf("%ce-%d",s[i],num2+1);
        }
        else
        {
            printf("%c.",s[i]);
            while(i!=len-1)
            {
                i++;
                printf("%c",s[i]);
            }
            printf("e-%d",num2+1);
        }
    }
        
}