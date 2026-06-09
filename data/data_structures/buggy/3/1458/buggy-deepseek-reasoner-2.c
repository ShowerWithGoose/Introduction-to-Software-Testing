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
    } // @@ Missing null terminator; after the loop, str is not null-terminated, causing strlen to exhibit undefined behavior.
    
    if(str[0]=='0')
    {
        for(i=2;i<strlen(str);i++) // @@ str is not null-terminated; strlen gives undefined result. Additionally, the condition should exclude the newline character (which is stored), causing off-by-one errors.
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ Same undefined strlen; also condition is incorrect due to newline presence.
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ Same undefined strlen; loop bound should be `j<strlen(str)-1` to include all digits before newline, current bound omits the last digit.
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ str not null-terminated; also condition may be off because newline is included.
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
            for(i=3;i<strlen(str);i++) // @@ Same undefined strlen; off-by-one due to newline.
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ Same undefined strlen and off-by-one.
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ Same undefined strlen and off-by-one.
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ Same undefined strlen and off-by-one.
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