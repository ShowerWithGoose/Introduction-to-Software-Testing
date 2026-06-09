#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [The condition is incorrect: it checks if 'a' is >= 'a' but does not ensure 'a' <= 'z'; similarly, it doesn't verify that 'b' >= 'a'. This allows mixed-type cases like 'B-e' to pass if 'b' > 'a' numerically, even though they are different types.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: 'a' might be lowercase or digit but still >= 'A', and 'b' might be lowercase but still <= 'Z'. The condition fails to confirm both characters are in the same valid range.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same problem: 'a' could be a letter >= '0' (which all letters are), and 'b' could be a letter <= '9' (which none are, but logic is still flawed). Should check both a and b are digits.]
        return 1;
    return 0;
}
int main()
{
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(i>=1&&i<strlen(s)-1)
        {
            if(s[i]=='-')
            {
                if(check(s[i-1],s[i+1]))
                {
                    for(char a=s[i-1]+1;a<s[i+1];a++)
                        printf("%c",a);
                }
                else
                    printf("%c",s[i]); // @@ [Missing else clause to print '-' when expansion is not performed. Without this, the '-' character is skipped entirely in non-expandable cases like "B-e", leading to output "Be" instead of "B-e".]
            }
            else
            {
                printf("%c",s[i]);
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}