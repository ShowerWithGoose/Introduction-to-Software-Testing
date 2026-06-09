#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ Potential out-of-bounds access if the string ends early; should check for '\n' or '\0' to prevent infinite loop or crash.
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]);
        cnt++;
        if(str[4]=='\n') // @@ Hardcoded index 4 is incorrect; it should check str[cnt] == '\n' to determine if there are remaining digits to print.
        printf("%c",str[e+1]); // @@ Incorrectly prints a character from index e+1; when no digits remain, nothing should be printed.
        else
        {
            printf(".");
            while(str[cnt]!='\n')
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1); // @@ The exponent calculation is flawed due to incorrect tracking of the decimal shift; it should be based on the position of the first significant digit relative to the decimal point.
    } 
    else
    {
        while(str[cnt]!='.')
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n') // @@ Hardcoded index 2 and condition are incorrect; should check if the fractional part is empty to decide on printing the decimal point.
        {
            for(i=1;i<len;i++) // @@ Loop logic is convoluted and may incorrectly handle digit printing or decimal point placement.
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