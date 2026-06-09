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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ [Condition is incorrect: should check both s[i-1] and s[i+1] are digits, but only checks s[i-1] >= '0' and s[i+1] <= '9', missing s[i-1] <= '9' and s[i+1] >= '0']
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ [Condition is incorrect: should check both s[i-1] and s[i+1] are lowercase letters, but only checks s[i-1] >= 'a' and s[i+1] <= 'z', missing s[i-1] <= 'z' and s[i+1] >= 'a']
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++)
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ [Condition is incorrect: should check both s[i-1] and s[i+1] are uppercase letters, but only checks s[i-1] >= 'A' and s[i+1] <= 'Z', missing s[i-1] <= 'Z' and s[i+1] >= 'A']
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