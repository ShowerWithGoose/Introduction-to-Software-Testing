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
            if(((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9'))||((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z'))||((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z'))) // @@ Missing check that str[i+1] > str[i-1]; also, when this condition is false, the code does nothing, so the '-' is omitted. Should copy '-' to ans.
            {
                for(int t=1;t<str[i+1]-str[i-1];t++) // @@ If str[i+1] <= str[i-1], this loop may not execute but the hyphen is still omitted; need to ensure str[i+1] > str[i-1] before expanding.
                {
                    ans[j]=str[i-1]+t;
                    j++;    
                }    
            }
        }
    }
    int len1=strlen(ans);
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}