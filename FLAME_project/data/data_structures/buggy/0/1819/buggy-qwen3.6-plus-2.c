#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char str[1010],ans[1010];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0,j=0;i<len;i++)
    {
        if(str[i]!='-')
        {
            ans[j]=str[i];
            j++;
        }
        else if(str[i]=='-')
        {
            if(((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9'))||((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z'))||((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')))
            {
                if (str[i+1] > str[i-1]) { // @@ The problem requires expansion only when the character after '-' is greater than the one before. Without this check, invalid ranges or reverse ranges might be processed incorrectly or output nothing while skipping the '-'. In the case of B-e, the types don't match, so it goes to else (implicit). But wait, if types don't match, the if condition is false.
                for(int t=1;t<str[i+1]-str[i-1];t++)
                {
                    ans[j]=str[i-1]+t;
                    j++;    
                }    
                } else { // @@ If the condition for expansion is met (same type) but the order is wrong (e.g., b-a), or if we just want to be safe, we should output the '-' if expansion doesn't happen. However, the main issue here is that if the `if` condition for same type fails, the code does nothing for the '-', effectively skipping it.
                     ans[j++] = str[i]; // @@ If the characters are not of the same type (like B and e), the expansion condition fails. The current code does nothing in the `else` case for the `-`, meaning the `-` is skipped and not added to `ans`. It should be added to preserve the original string.
                }
            }
            else { // @@ This else corresponds to the type check. If types are different (like B and e), the '-' should be preserved.
                ans[j++] = str[i]; // @@ The '-' character needs to be added to the output if expansion is not performed.
            }
        }
    }
    int len1=strlen(ans);
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}