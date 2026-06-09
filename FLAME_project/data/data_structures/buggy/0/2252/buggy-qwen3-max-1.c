#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using gets() is unsafe and deprecated; more critically, the logic does not handle cases where '-' appears at start/end or adjacent to mismatched types correctly]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check both s[i-1] and s[i+1] are digits using isdigit or proper range checks like (s[i-1]>='0' && s[i-1]<='9') && (s[i+1]>='0' && s[i+1]<='9')]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should ensure both characters are lowercase letters, but current check allows e.g., 'A'-'z' to pass if s[i-1]>='a' and s[i+1]<='z', which is logically flawed]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Same issue: incomplete type checking; doesn't verify s[i+1] >= 'A' or s[i-1] <= 'Z']
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else
            {
                printf("%c",s[i]); // @@ [This handles non-expansion cases, but due to flawed conditions above, cases like 'B-e' incorrectly fall through to expansion logic instead of printing '-']
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("%s",s1); // @@ [s1 is never assigned any value, so this prints garbage or empty string; also, output is interleaved with direct printf calls, causing incorrect ordering and duplication]
    return 0;
}