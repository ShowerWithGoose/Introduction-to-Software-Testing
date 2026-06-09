#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
    int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
    
    while(str[i]=getchar())
    {
        if(str[i]=='\n')
        {
            break;
        }
        if(str[i]=='.')
        {
            flag=1;
        }
        if(flag==0)
        {
            cnt_f++;
        }
        else
        {
            cnt_b++;
        }
        i++;
    }
    
    if(str[0]=='0')
    {
        for(i=2;i<strlen(str);i++)
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ [This condition is incorrect. It should check whether there are digits after the first non-zero digit to decide if a decimal point is needed. The "-2" assumes newline and null terminator, but strlen doesn't count newline since it's not stored as part of the string in this logic. Also, if input is "0.9", strlen(str) is 3 (including '\0'), so strlen(str)-2 = 1, and i starts at 2, so i<1 is false, skipping the decimal point even though it shouldn't for multi-digit mantissa. However, in "0.9", there's only one significant digit, so no decimal point should be printed, but the bigger issue is below.]
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ [This loop bound is wrong. The string does not include the newline character because the loop breaks on '\n' and doesn't store it. So strlen(str) gives the length including the null terminator, but the actual digits end at index i-1. For input "0.9", str becomes "0.9\0", so strlen=3. Then j starts at i=2 (pointing to '9'), and condition j < 3-2 → j<1, so loop doesn't run, and '9' is never printed after the initial printf. Thus, nothing is printed after the first digit, leading to missing output.]
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ [The loop bound strlen(str)-1 is incorrect. Since the newline is not stored in str, strlen(str) returns the correct length of the input string (e.g., "12.34" → length 5). But subtracting 1 skips the last digit. For example, if input is "1.2", str is "1.2\0", strlen=3, so i goes from 1 to <2, so only i=1 ('.') is processed and skipped, and '2' at i=2 is never printed.]
        {
            if(str[i]=='.')
            {
                continue;
            }
            printf("%c",str[i]);
        }
        printf("e%d",cnt_f-1);
    }
    else
    {
        printf("-");
        if(str[1]=='0')
        {
            for(i=3;i<strlen(str);i++)
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ [Same issue as above: incorrect bound due to misunderstanding of string length and content.]
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ [Same issue: loop may not execute due to overly restrictive bound, causing missing digits.]
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ [Same off-by-one error as in the positive non-zero case: last digit may be omitted.]
            {
                if(str[i]=='.')
                {
                    continue;
                }
                printf("%c",str[i]);
            }
            printf("e%d",cnt_f-2);
        }
    }
    return 0;
}