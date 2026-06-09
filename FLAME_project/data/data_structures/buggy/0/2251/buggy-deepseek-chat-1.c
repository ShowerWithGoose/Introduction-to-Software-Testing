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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Error: The condition only checks if s[i+1] <= '9', but does not ensure s[i-1] <= '9' and s[i+1] >= '0'. It should be: s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Error: The loop prints s[i-1]+j, which includes s[i-1] itself. It should start from j=1 to exclude s[i-1], or change condition to j<lenth-1 to exclude s[i+1]. The expected output should not include the start character.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Error: Same issue as above; should check both ends: s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Error: Same loop issue; should start from j=1 to exclude s[i-1]
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Error: Same issue; should check both ends: s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Error: Same loop issue; should start from j=1 to exclude s[i-1]
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