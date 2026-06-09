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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Condition does not ensure both characters are digits (should check s[i-1]<='9' && s[i+1]>='0')
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Loop should start from j=1 to exclude the left character; also should print up to s[i+1]-1 (exclude right)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Condition does not ensure both characters are lowercase (should check s[i-1]<='z' && s[i+1]>='a')
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Same loop error: should start from j=1
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Condition does not ensure both characters are uppercase (should check s[i-1]<='Z' && s[i+1]>='A')
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Same loop error: should start from j=1
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