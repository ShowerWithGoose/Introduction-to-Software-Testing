#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ [This loop may access out-of-bounds memory if the input is "0.9" because cnt+2 could exceed string length; also, it assumes at least two characters after '0.', which fails for short inputs like "0.9"]
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]); // @@ [For input "0.9", cnt becomes 2 (after cnt+=2), so str[2] is '9', which is correct, but the following logic is flawed]
        cnt++;
        if(str[4]=='\n') // @@ [This checks a fixed index (4) which is invalid for short inputs like "0.9" (which has length 4 including newline: "0.9\n"), leading to incorrect branching]
        printf("%c",str[e+1]); // @@ [This prints an extra digit that shouldn't be there in scientific notation when base is integer; also e+1 may not be valid]
        else
        {
            printf(".");
            while(str[cnt]!='\n')
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1); // @@ [The exponent calculation is off by one; for "0.9", it should be -1, but e starts at 0 and e+1 gives -1 only if e was -1, which it isn't]
    } 
    else
    {
        while(str[cnt]!='.')
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n') // @@ [This condition assumes specific string layout; for example, "1.2\n" has str[2]='2', not '\n', so it fails to handle single-digit cases correctly]
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