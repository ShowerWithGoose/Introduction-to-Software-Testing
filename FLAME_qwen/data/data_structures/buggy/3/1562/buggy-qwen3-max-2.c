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
        if(str[4]=='\n') // @@ [This condition assumes a fixed input length (e.g., "0.00x\n" with x at index 4), which fails for inputs with different numbers of leading zeros or digits. It should check based on actual parsed positions, not hardcoded index 4.]
        printf("%c",str[e+1]); // @@ [This prints an incorrect digit when the condition above is true; it should not print an extra digit without a decimal point and may access invalid or unintended characters. Also, logic for handling single-digit mantissa is flawed.]
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
        if(e==0&&str[2]=='\n') // @@ [This condition assumes that if exponent is 0, the input must be of the form "d.\n" (length 3), but fails for inputs like "1.2\n" where e=0 but more digits exist. The check str[2]=='\n' is too restrictive and ignores valid longer inputs.]
        {
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]); // @@ [In this branch, it prints additional digits without a decimal point, violating scientific notation format which requires either a single digit (no decimal) or one digit before and some after a decimal point. For example, "12" would be printed as "12", but should be "1.2".]
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