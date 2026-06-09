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
    str[i] = '\0'; // @@ [The original code does not null-terminate the string after reading input with getchar(), leading to undefined behavior when using strlen() and accessing beyond valid input.]
    
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
        if(i<strlen(str)-2) // @@ [This condition is incorrect; it should check whether there are digits after the first non-zero digit to decide if a decimal point is needed. Also, due to missing null termination, strlen() may read garbage.]
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ [The loop bound strlen(str)-2 is arbitrary and wrong; it likely stems from misunderstanding input length. It should go up to strlen(str) or stop at '\0'.]
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1);
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ [Using strlen(str)-1 as upper bound is incorrect; it skips the last character unnecessarily. Should iterate until str[i] != '\0'.]
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
            if(i<strlen(str)-2) // @@ [Same issue as above: incorrect bound for deciding decimal point presence.]
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ [Same incorrect loop bound as earlier; leads to missing or extra characters in output.]
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2);
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ [Again, incorrect upper bound strlen(str)-1 causes last digit(s) to be omitted.]
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