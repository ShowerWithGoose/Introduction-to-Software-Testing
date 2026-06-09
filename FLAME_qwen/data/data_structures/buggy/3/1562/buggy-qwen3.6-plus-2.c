#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ Potential out-of-bounds access if the string ends before a non-zero digit is found; should check for '\0' or '\n'.
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]);
        cnt++;
        if(str[4]=='\n') // @@ Hardcoded index 4 is incorrect for inputs of varying lengths; should dynamically check if the remaining part is empty.
        printf("%c",str[e+1]); // @@ Incorrectly prints an extra digit when the decimal part has only one significant digit, resulting in an invalid mantissa.
        else
        {
            printf(".");
            while(str[cnt]!='\n')
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1);
    } 
    else
    {
        while(str[cnt]!='.')
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n') // @@ Hardcoded index 2 and condition are flawed; fails to correctly handle cases where the decimal part has only one digit or varies in length.
        {
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]);
        }
        }
        else
        {
            printf(".");
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]);
        }
        }
        printf("e%d",e);
    }
    return 0;
}