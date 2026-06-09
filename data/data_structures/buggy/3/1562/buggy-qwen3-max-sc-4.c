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
        if(str[4]=='\n') // @@ [This condition assumes a fixed input length (e.g., "0.00x\n"), but the input can be of any valid length. It should check whether there are more digits after the first non-zero digit instead.]
        printf("%c",str[e+1]); // @@ [This prints an incorrect character; it should not print anything extra here because the decimal part has already started. Also, str[e+1] may be out of bounds or refer to a zero that was skipped.]
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
        if(e==0&&str[2]=='\n') // @@ [This condition assumes that if exponent is 0, the input must be like "d.\n" with only one digit before '.', but input could be longer (e.g., "5.678"). This leads to missing decimal point and fractional digits in some cases.]
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