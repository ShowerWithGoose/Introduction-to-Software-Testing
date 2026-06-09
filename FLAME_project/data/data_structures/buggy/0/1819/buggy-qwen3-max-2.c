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
                for(int t=1;t<str[i+1]-str[i-1];t++)
                {
                    ans[j]=str[i-1]+t;
                    j++;    
                }    
            }
            else
            {
                ans[j] = str[i]; // @@ [When the '-' does not meet expansion conditions (e.g., mixed types or invalid range), it should be copied to output as-is. The original code skips copying '-', leading to missing '-' in output like "B-e" becoming "Be".]
                j++;
            }
        }
    }
    ans[j] = '\0'; // @@ [The ans array is not null-terminated, which causes undefined behavior when using strlen() later. This leads to incorrect output length and possible garbage characters.]
    int len1=strlen(ans);
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}