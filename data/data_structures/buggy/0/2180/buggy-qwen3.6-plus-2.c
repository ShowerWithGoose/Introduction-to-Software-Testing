#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++) // @@ Loop condition lacks '\0' check, risking out-of-bounds access or infinite loop if input doesn't end with a newline.
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ Accesses s[i-1] when i=0 causing undefined behavior; checks ASCII order before type validation, causing '-' to be omitted when types differ but right char has higher ASCII value.
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
            else // @@ Only handles cases where s[i+1]<=s[i-1], failing to print '-' when types mismatch but s[i+1]>s[i-1].
            printf("%c",s[i]);
        }
        else
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}