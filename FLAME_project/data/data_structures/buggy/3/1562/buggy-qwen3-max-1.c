#include<stdio.h>
#include<string.h>
int main()
{
    char str[105];
    fgets(str,104,stdin);
    int e=0,cnt=0,len=strlen(str),i=0;
    if(str[0]=='0')
    {
        while(str[cnt+2]=='0') // @@ [If the input is "0.9", then cnt+2 = 2, and str[2] is '9', so the loop doesn't run. But if the input were "0.009", this would work. However, the logic for determining where the first non-zero digit is located is flawed because it assumes at least one zero after the decimal point. Also, if the string length is small (like "0.9\n"), accessing str[cnt+2] may go out of intended bounds or misalign indexing.]
        {
            cnt++;
        }
        e=cnt;
        cnt+=2;
        printf("%c",str[cnt]); // @@ [For input "0.9", cnt becomes 2, so str[2] is '9' — this is correct. But if there were more digits, this prints only the first significant digit, which is okay per spec. However, the following logic for printing fractional part is broken.]
        cnt++;
        if(str[4]=='\n') // @@ [This checks a fixed index (4), which assumes the input has exactly 4 characters including newline (e.g., "0.9\n" is 4 chars: indices 0–3). But "0.9\n" has len=4, so str[4] is out-of-bounds (undefined behavior). This causes runtime error or incorrect branching. Should check based on actual position of '\n' or use len.]
        printf("%c",str[e+1]); // @@ [This line is unreachable in "0.9" case due to wrong condition above, and even if reached, str[e+1] may not be meaningful. Also, per problem spec, if base is integer (only one digit), no decimal point should be printed. But logic here is inconsistent.]
        else
        {
            printf(".");
            while(str[cnt]!='\n') // @@ [After incrementing cnt post printing first digit, this loop prints rest. But if input is "0.9", cnt=3, and str[3] is '\n', so loop doesn't run — correct. However, the earlier out-of-bound access in str[4] already causes undefined behavior.]
        {
            printf("%c",str[cnt]);
            cnt++;
        }
        }
        printf("e-%d",e+1); // @@ [For "0.9", e=0, so prints e-1 — correct exponent. But due to earlier errors, program may crash before this.]
    } 
    else
    {
        while(str[cnt]!='.') // @@ [This finds decimal point. OK for numbers like "123.45".]
        {
            cnt++;    
        } 
        e=cnt-1;
        printf("%c",str[0]);
        if(e==0&&str[2]=='\n') // @@ [Again, hard-coded index 2 assumes very specific input format like "1.2\n" being 4 chars. If input is "1.23\n", str[2] is '2', not '\n', so condition fails — but that's okay. However, if input is "5\n" (no decimal), this branch wouldn't be taken because str[0]!='0' but there's no '.', causing infinite loop in while(str[cnt]!='.') since '.' never found — but problem states input always has digits before and after decimal, so maybe safe. Still, fragile.]
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