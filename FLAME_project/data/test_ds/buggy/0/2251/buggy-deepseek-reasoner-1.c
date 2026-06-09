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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Condition incomplete: should also check s[i-1]<='9' and s[i+1]>='0' to ensure both are digits.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ Prints the left character again; should start from s[i-1]+1 to exclude the left endpoint.
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Condition incomplete: should also check s[i-1]<='z' and s[i+1]>='a' to ensure both are lowercase letters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ Same error: includes the left character.
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Condition incomplete: should also check s[i-1]<='Z' and s[i+1]>='A' to ensure both are uppercase letters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j); // @@ Same error: includes the left character.
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}