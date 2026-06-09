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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Error: The condition should check both characters are digits, but s[i-1]>='0' only checks the lower bound, missing the upper bound check s[i-1]<='9'. Also, the condition s[i+1]<='9' is correct but the lower bound s[i+1]>='0' is missing. This can cause incorrect expansion when characters are outside the digit range.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Error: Similar issue - missing upper bound check for s[i-1] (should be s[i-1]<='z') and lower bound check for s[i+1] (should be s[i+1]>='a'). This may cause incorrect expansion for non-lowercase characters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Error: Same issue - missing upper bound check for s[i-1] (should be s[i-1]<='Z') and lower bound check for s[i+1] (should be s[i+1]>='A'). This may cause incorrect expansion for non-uppercase characters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}