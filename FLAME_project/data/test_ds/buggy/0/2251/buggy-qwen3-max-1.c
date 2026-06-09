#include <stdio.h>
#include <string.h> 

char s[10000000];
int i,len,j,lenth;

int main()
{
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ [Condition is incorrect: it checks s[i-1] >= '0' but does not ensure s[i+1] >= '0'; similarly, it checks s[i+1] <= '9' but not s[i-1] <= '9'. This allows mixed-type cases like 'a-9' to incorrectly pass the digit check.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ [This prints from s[i-1] to s[i+1]-1 inclusive, but includes the starting character again. It should start from s[i-1]+1 to s[i+1]-1 to avoid duplicating the left character. Also, the loop runs lenth times which equals (s[i+1]-s[i-1]), so it prints s[i-1], s[i-1]+1, ..., s[i+1]-1 — but the original character s[i-1] was already printed in the previous iteration, causing duplication.]
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ [Same issue as above: missing lower bound check for s[i+1] and upper bound check for s[i-1]. Should verify both characters are in [a-z].]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ [Same duplication issue: prints the left character again, which was already output before encountering '-'.]
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ [Same issue: missing validation that both characters are uppercase letters.]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ [Same duplication issue.]
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}