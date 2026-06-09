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
    str[i] = '\0'; // @@ The string is not null-terminated after reading input, causing strlen and loop conditions to read garbage memory, leading to Runtime Error or incorrect output.
    
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
        if(i<strlen(str)-2) // @@ Logic error in determining if decimal point is needed. For "0.9", i becomes 2, strlen is 3. 2 < 3-2 (1) is false, so no dot printed. Correct logic should check if there are remaining digits after the first non-zero digit.
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ Loop bound is incorrect. It stops before the last character of the original string (excluding newline), potentially truncating significant digits or accessing invalid memory if strlen calculation is off due to missing null terminator.
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ Loop bound excludes the last digit because of -1. For "12.34", it prints "1." then loops i=1 to <4. i=1 ('2'), i=2 ('.' skip), i=3 ('3'). '4' is missed.
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
            if(i<strlen(str)-2)
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++)
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ Same error as above: loop bound excludes the last digit.
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