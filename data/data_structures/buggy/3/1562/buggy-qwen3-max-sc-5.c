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
        if(str[4]=='\n') // @@ [This condition assumes a fixed input length (e.g., "0.00x\n" with x at index 4), which fails for inputs with different numbers of leading zeros or digits. It should check the actual position after skipping zeros instead of hardcoding index 4.]
        printf("%c",str[e+1]); // @@ [This prints an incorrect character when the condition above is true; it should not print anything extra here because the normalized form already printed the first non-zero digit and shouldn't add another digit without a decimal point. Also, str[e+1] may be out of bounds or refer to a zero that was skipped.]
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
        if(e==0&&str[2]=='\n') // @@ [This condition assumes that if exponent is 0, the input must be of the form "d.\n" (length 3 including newline), but inputs like "5.6\n" would have e=0 yet more digits after decimal. This leads to missing the decimal part in output.]
        {
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]); // @@ [In this branch, it prints additional digits without a decimal point, violating scientific notation format which requires either a single digit (if integer) or one digit before and after decimal. For example, input "5.6" would incorrectly output "56e0" instead of "5.6e0".]
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