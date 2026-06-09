#include <stdio.h>
#include <string.h>
char s[]={}; // @@ Array size is 0, causing buffer overflow when reading input. Should be declared with a sufficient size like char s[1000];
int main()
{
    scanf("%s", s);
    int y=strlen(s);
    for(int i=0; i<y; i++)
    {
        if(s[i]!='-')
        {
            printf("%c", s[i]);
        }
        if(s[i]=='-')
        {
            if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++) // @@ Loop condition uses '<' which excludes the end character s[i+1]. Should be '<=' to correctly include the end character in the expansion.
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++) // @@ Same off-by-one error: '<' excludes the end character. Should be '<='.
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++) // @@ Same off-by-one error: '<' excludes the end character. Should be '<='.
                {
                    printf("%c", s[i-1]+j);
                }
            }
        } // @@ Missing else branch to print '-' when expansion conditions are not met, causing the '-' symbol to be omitted from the output.
    }
    return 0;    
}