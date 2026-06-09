#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ This loop incorrectly assumes the input always has a decimal point at index 1, but for "0.9", str[2] is '9', not '0', so the loop doesn't execute, but the logic for handling trailing zeros is flawed.
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]); // @@ For input "0.9", cnt becomes 2, so str[2] is '9', which is correct, but the exponent calculation later is wrong.
        cnt++;
        if(str[4]=='\n') // @@ This condition assumes the string has at least 5 characters, but "0.9" has only 4 characters (including newline), so str[4] is out of bounds, causing undefined behavior (runtime error).
        printf("%c",str[e+1]); // @@ This line is only reached if str[4]=='\n', which is not the case for "0.9", but the out-of-bounds access already occurred.
        else
        {
            printf(".");
            while(str[cnt]!='\n')
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1); // @@ For "0.9", e=0, so exponent is -1, but expected is -1, so this part is correct, but the earlier out-of-bounds access causes the program to crash before reaching here.
    } 
    else
    {
        while(str[cnt]!='.')
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n')
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