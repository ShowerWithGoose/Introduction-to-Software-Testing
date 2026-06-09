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
                if (str[i+1] > str[i-1]) { // @@ The problem requires expansion only when the character after '-' is greater than the one before. Without this check, invalid ranges or reverse ranges might be processed incorrectly or produce empty output while skipping the '-' itself.
                    for(int t=1;t<str[i+1]-str[i-1];t++)
                    {
                        ans[j]=str[i-1]+t;
                        j++;    
                    }    
                } else { // @@ If the condition for expansion is not met (types match but order is wrong, or types don't match which is already filtered by outer if, but specifically here if start >= end), the '-' should be output as is. Currently, the code does nothing in the else case for '-', effectively deleting it.
                    ans[j] = str[i];
                    j++;
                }
            }
            else { // @@ If the characters around '-' are not of the same type, the '-' should be preserved in the output. The current code skips adding anything to ans when this else branch is taken, effectively deleting the '-'.
                ans[j] = str[i];
                j++;
            }
        }
    }
    int len1=strlen(ans);
    for(int i=0;i<len1;i++)
    printf("%c",ans[i]);
     return 0;
}