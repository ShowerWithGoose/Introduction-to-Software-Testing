#include <stdio.h>
#include <string.h>
char s[]={}; // @@ Array size is 0, causing buffer overflow/undefined behavior when reading input with scanf.
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
        if(s[i]=='-') // @@ Missing an else clause to print '-' when expansion conditions are not met, causing '-' to be omitted from the output.
        {
            if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++) // @@ Loop condition uses '<' instead of '<=', failing to print the end character of the expansion range.
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++) // @@ Loop condition uses '<' instead of '<=', failing to print the end character of the expansion range.
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++) // @@ Loop condition uses '<' instead of '<=', failing to print the end character of the expansion range.
                {
                    printf("%c", s[i-1]+j);
                }
            }
        }
    }
    return 0;    
}