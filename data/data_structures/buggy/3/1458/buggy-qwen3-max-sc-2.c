#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
    int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
    
    while(str[i]=getchar()) // @@ [The loop condition is incorrect: getchar() returns EOF on end-of-file or error, which may be negative; also, the loop doesn't stop at '\n' correctly because assignment happens before check. Moreover, the string is not null-terminated, leading to undefined behavior in subsequent strlen() calls.]
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
        for(i=2;i<strlen(str);i++) // @@ [strlen(str) is undefined behavior because 'str' is not null-terminated due to the faulty input loop.]
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ [Again, strlen(str) is invalid; also, logic assumes fixed structure that may not hold.]
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ [Invalid strlen usage and off-by-one errors likely due to missing null terminator and incorrect length assumptions.]
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ [strlen(str) is undefined; also, subtracting 1 assumes newline is part of string, but input loop breaks on '\n' without storing it, so string lacks newline and null terminator.]
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
            for(i=3;i<strlen(str);i++) // @@ [strlen(str) undefined; same root cause: missing null terminator.]
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ [Invalid strlen and incorrect offset assumptions.]
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ [Invalid strlen and boundary errors.]
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ [Invalid strlen usage due to non-null-terminated string.]
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