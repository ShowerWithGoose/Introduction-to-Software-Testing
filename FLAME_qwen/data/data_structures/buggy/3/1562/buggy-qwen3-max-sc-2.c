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
        if(str[4]=='\n') // @@ [This condition assumes a fixed input length and position of '\n', which is incorrect. It should check the actual position of '\n' relative to current parsing state, not hardcoded index 4.]
        printf("%c",str[e+1]); // @@ [This prints an extra digit without proper context; it may print beyond significant digits or duplicate digits. Also, str[e+1] might be out of bounds or not the intended digit.]
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
        if(e==0&&str[2]=='\n') // @@ [This condition assumes that if exponent is 0, then newline must be at index 2, which fails for inputs like "5.678\\n" where len > 3. Should check actual length or presence of more digits after decimal.]
        {
            for(i=1;i<len;i++)
        {
            if(str[i]=='.'||str[i]=='\0'||str[i]=='\n')
            continue;
            printf("%c",str[i]); // @@ [In this branch, it prints digits after the first without a decimal point, but according to spec, if there's only one digit before decimal and more after, it should show as d.d... So missing decimal point here leads to wrong format like "567" instead of "5.67".]
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