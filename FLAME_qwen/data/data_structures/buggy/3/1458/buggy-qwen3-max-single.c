#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
    int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
    
    while(str[i]=getchar()) // @@ [The loop condition is incorrect: getchar() returns EOF on end-of-file or error, which may be -1, and assigning it to str[i] then checking truthiness will not correctly detect newline-only termination. Also, the null terminator is never added to str, leading to undefined behavior in subsequent strlen calls.]
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
        for(i=2;i<strlen(str);i++) // @@ [strlen(str) is used on a non-null-terminated array, causing undefined behavior. The input loop does not null-terminate str, so strlen may read beyond valid data.]
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ [Again, strlen(str) is unsafe due to missing null terminator. Additionally, logic assumes fixed offset (e.g., "-2") that doesn't account for actual string length or decimal position correctly.]
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ [Same issue: strlen on unterminated string; also, off-by-one errors likely due to misunderstanding of where digits start/end relative to decimal point and newline.]
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ [strlen(str) is invalid without null termination; also, subtracting 1 assumes newline is last char but doesn't account for whether it was stored or how string ends.]
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
            for(i=3;i<strlen(str);i++) // @@ [strlen(str) used on non-null-terminated array → undefined behavior.]
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ [Same: unsafe strlen and incorrect offset assumptions.]
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ [Unsafe strlen and likely wrong bounds due to missing handling of actual input structure.]
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ [strlen(str) is undefined; loop bound assumes newline at end but string isn't properly terminated.]
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