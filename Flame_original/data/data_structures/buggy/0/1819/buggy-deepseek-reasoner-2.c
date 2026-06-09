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
            if(((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9'))||((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z'))||((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z'))) // @@ Missing check that str[i+1] > str[i-1] (expansion should only occur when the character after '-' is greater than the one before)
            {
                for(int t=1;t<str[i+1]-str[i-1];t++)
                {
                    ans[j]=str[i-1]+t;
                    j++;    
                }    
            } // @@ Missing else clause to output '-' when expansion condition fails (e.g., for invalid expansions, the '-' should be copied unchanged)
        }
    }
    int len1=strlen(ans); // @@ ans is not null-terminated, strlen may cause undefined behavior; should add ans[j] = '\0' before this line
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}