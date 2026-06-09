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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Error: The condition only checks s[i+1] <= '9' but does not check s[i-1] <= '9', so it may incorrectly match characters like '0' to ':' (since ':' > '9'). Also, the loop prints s[i-1] itself, but the expansion should start from s[i-1]+1.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ Error: This prints s[i-1] itself (when j=0), but the expansion should start from s[i-1]+1. Also, it prints the end character s[i+1] when j = lenth-1, but the expansion should stop before s[i+1].
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Error: Same issue as above for lowercase letters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ Error: Same issue as above.
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Error: Same issue as above for uppercase letters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ Error: Same issue as above.
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}