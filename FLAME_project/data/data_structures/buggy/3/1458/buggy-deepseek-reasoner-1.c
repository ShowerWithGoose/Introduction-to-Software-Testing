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
    } // @@ Missing null terminator at str[i] after reading input; strlen() will read beyond allocated memory, causing undefined behavior and likely runtime error.
    
    if(str[0]=='0')
    {
        for(i=2;i<strlen(str);i++) // @@ Loop condition uses strlen() which is unreliable due to missing null terminator; also variable i is reused, but the main issue is undefined length.
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ Incorrect condition for printing decimal point; should check if there are additional digits after i (i+1 < strlen(str)). Using strlen again is also unsafe.
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ Loop should start from i+1 (to avoid repeating the first significant digit) and should go to strlen(str) (excluding null), not strlen(str)-2.
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++)
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
            if(i<strlen(str)-2) // @@ Same error as line 43: incorrect condition for printing decimal point.
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ Same error as line 47: loop should start at i+1 and go to end of string.
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++)
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