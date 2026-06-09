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
        if(i<strlen(str)-2) // @@ The condition for printing the decimal point is incorrect. For input "0.9", i becomes 2 and strlen(str) is 3 (assuming null terminator or just length logic). If the loop breaks at the first non-zero digit, we need to check if there are more digits after it. The current logic `i < strlen(str) - 2` fails to print the dot when there is exactly one significant digit after the leading zeros, or miscalculates the boundary. Specifically, for "0.9", i=2, strlen(str)=3 (if newline stripped) or 4. If newline is part of str, strlen is 4. "0.9\n". i=2. str[2]='9'. Loop breaks. i=2. strlen(str)-2 = 2. 2 < 2 is false. So "." is not printed. Output becomes "9e-1" wait, if dot is not printed, it prints "9". Then the next loop runs.
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ This loop range is also problematic. It stops before the last character(s). For "0.9", if newline is included, strlen is 4. j starts at 2. Condition j < 4-2=2. Loop doesn't run. This might be okay if only one digit. But combined with the missing dot, the format is wrong. However, the primary issue described as Runtime Error might stem from accessing out of bounds or logical infinite loops in other cases, but here for "0.9", the output is "9e-1" if the dot logic was correct? No, expected is "9e-1". Wait, scientific notation for 0.9 is 9e-1. The base is 9 (integer). The problem says: "If it’s an integer, it contains only one significant digit without a decimal point." So "9e-1" is correct. The code prints "9" then no dot, then no more digits, then "e-1". This seems correct for 0.9? Let's re-read carefully.
        // Actually, let's look at the "Runtime Error".
        // The `while(str[i]=getchar())` loop does not null-terminate the string properly if it breaks on '\n'.
        // It stores '\n' in str[i] then breaks. It does NOT add '\0'.
        // strlen(str) will then read beyond the buffer until it finds a random '\0', causing undefined behavior (Runtime Error).
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ strlen(str) is unsafe because str is not null-terminated.
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
            for(i=3;i<strlen(str);i++) // @@ strlen(str) is unsafe because str is not null-terminated.
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ strlen(str) is unsafe.
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ strlen(str) is unsafe.
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ strlen(str) is unsafe.
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