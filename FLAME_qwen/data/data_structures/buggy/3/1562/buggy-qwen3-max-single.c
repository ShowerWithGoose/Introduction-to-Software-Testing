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
        if(str[4]=='\n') // @@ [This condition assumes a fixed position (index 4) for newline, which is incorrect as input length varies. It should check the actual position of '\n' or use len to determine structure.]
        printf("%c",str[e+1]); // @@ [This prints an arbitrary character based on e+1 without verifying it's part of the significant digits; also, logic doesn't align with scientific notation format when only one digit follows.]
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
        if(e==0&&str[2]=='\n') // @@ [This condition assumes that if exponent is 0, the input must be like "d.\n" (3 characters), but input could be longer (e.g., "5.67\n"), so checking str[2] is unreliable.]
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