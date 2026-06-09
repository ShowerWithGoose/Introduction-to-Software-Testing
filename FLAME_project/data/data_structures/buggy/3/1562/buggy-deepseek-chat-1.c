#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ The condition may cause out-of-bounds access when cnt+2 exceeds the string length, and it incorrectly assumes the decimal point is always at index 1.
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]);
        cnt++;
        if(str[4]=='\n') // @@ This hardcoded index 4 is incorrect for general inputs; it assumes a specific format (e.g., "0.9" has length 3, so str[4] is out of bounds).
        printf("%c",str[e+1]); // @@ This prints the digit after the decimal point incorrectly; for "0.9", e=0, so str[1] is '.' not '9'.
        else
        {
            printf(".");
            while(str[cnt]!='\n')
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1); // @@ The exponent should be e+1 only when the first non-zero digit is after leading zeros; for "0.9", e=0, exponent should be 1, but the logic is flawed.
    } 
    else
    {
        while(str[cnt]!='.')
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n') // @@ This condition is too specific and may fail for inputs like "1.0" (which is not allowed per spec) or other cases; also str[2] may be out of bounds for short strings.
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