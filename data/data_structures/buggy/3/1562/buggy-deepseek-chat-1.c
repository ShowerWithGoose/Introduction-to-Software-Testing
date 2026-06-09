#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0')
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]);
        cnt++;
        if(str[4]=='\n') // @@ [Error: This condition assumes the input has a specific structure (e.g., "0.xxx") and uses a fixed index 4, which fails for inputs like "0.0" or "0.00...". It should check if the next character after the first non-zero digit is newline, not a fixed position.]
        printf("%c",str[e+1]); // @@ [Error: This prints a character at index e+1, which may be a '0' or '.' and is not the correct digit for the fractional part. The logic for handling the case where the number is just "0.x" with no trailing digits is flawed.]
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
        if(e==0&&str[2]=='\n') // @@ [Error: This condition assumes the input has exactly one digit before decimal and one digit after (e.g., "1.2"), but fails for cases like "1.23" or "12.3". It should check if there are no more digits after the decimal point, not a fixed index.]
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