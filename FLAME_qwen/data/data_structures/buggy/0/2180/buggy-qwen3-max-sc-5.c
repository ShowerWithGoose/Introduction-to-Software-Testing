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
            if(s[i+1]>s[i-1]) // @@ [This condition is evaluated before checking if the surrounding characters are valid and of the same type. It may access s[-1] when i=0, causing undefined behavior. Also, it does not ensure both sides are of the same category (e.g., letter/digit).]
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