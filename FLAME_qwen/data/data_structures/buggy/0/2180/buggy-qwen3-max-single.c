#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++)
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ [This condition is evaluated before checking if the surrounding characters are of the same valid type and may cause undefined behavior when i=0 (s[i-1] accesses s[-1]) or when s[i+1] is '\0' or '\n'. Also, it skips printing '-' when s[i+1] <= s[i-1], but according to requirements, '-' should be printed unchanged in invalid cases, including when the range is non-increasing. However, the bigger issue is potential out-of-bounds access.]
            {
                if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<= 'z')
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
            }
            else
            printf("%c",s[i]);
        }
        else
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}