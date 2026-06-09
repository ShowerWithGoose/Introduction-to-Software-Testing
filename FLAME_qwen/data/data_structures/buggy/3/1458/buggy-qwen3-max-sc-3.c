#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
    int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
    
    while(str[i]=getchar()) // @@ [The loop condition is incorrect: getchar() returns EOF on end-of-file or error, which may be -1 (non-zero), causing infinite loop. Also, it stores '\n' into str but doesn't null-terminate the string, leading to undefined behavior in strlen().]
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
        for(i=2;i<strlen(str);i++) // @@ [strlen(str) is undefined because str is not null-terminated. This leads to reading uninitialized memory and unpredictable results.]
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ [Again uses strlen on non-null-terminated string; also logic for decimal point placement is flawed.]
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ [Same issue with strlen; also off-by-one errors likely due to including/excluding newline incorrectly.]
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ [Uses strlen on non-null-terminated array; also assumes newline is at end but doesn't account for it properly.]
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
            for(i=3;i<strlen(str);i++) // @@ [strlen on non-null-terminated string; same fundamental flaw throughout.]
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ [Incorrect boundary check due to missing null terminator and misunderstanding of input length.]
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ [Same issues as above.]
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ [Relies on strlen without null termination—undefined behavior.]
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