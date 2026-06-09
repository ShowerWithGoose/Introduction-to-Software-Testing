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
                if(str[i+1] > str[i-1]) // @@ [Missing check that the character after '-' is greater than the one before; without this, cases like 'e-B' or equal characters may cause incorrect behavior or infinite loops]
                {
                    for(int t=1;t<str[i+1]-str[i-1];t++)
                    {
                        ans[j]=str[i-1]+t;
                        j++;    
                    }
                }
                else
                {
                    ans[j]='-'; // @@ [When the condition for expansion is not met (e.g., B-e), the '-' should be copied to output, but current code skips it entirely]
                    j++;
                }
            }
            else
            {
                ans[j]='-'; // @@ [If the characters around '-' are not of the same type, the '-' should be preserved in output, but current code omits it]
                j++;
            }
        }
    }
    ans[j] = '\0'; // @@ [Missing null termination of ans string, which leads to undefined behavior when printing with %c loop or if using puts/printf("%s")]
    int len1=strlen(ans);
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}