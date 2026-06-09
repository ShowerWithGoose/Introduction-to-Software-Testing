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
                for(int t=1;t<str[i+1]-str[i-1];t++) // @@ The loop condition should be t <= str[i+1]-str[i-1]-1, but more importantly, the code does not check if str[i+1] > str[i-1] before expanding. For input "B-e", str[i-1]='B' and str[i+1]='e', they are not the same type (uppercase vs lowercase), so the condition fails and the '-' is not copied to ans, causing it to be lost.
                {
                    ans[j]=str[i-1]+t;
                    j++;    
                }    
            }
            // @@ Missing else clause: when the condition fails (e.g., different types or str[i+1] <= str[i-1]), the '-' character should be copied to ans. Without this, the '-' is omitted from the output.
        }
    }
    int len1=strlen(ans);
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}