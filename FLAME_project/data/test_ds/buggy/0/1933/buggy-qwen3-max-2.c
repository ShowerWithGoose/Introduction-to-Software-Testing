#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [The condition is incorrect: it checks if 'a' is >= 'a' and 'b' <= 'z', but does not ensure 'a' is also <= 'z'. This allows invalid pairs like 'B' (uppercase) and 'e' (lowercase) to pass if 'B' >= 'a' (which is false, but similar logic errors exist in other branches). Also, the requirement is that both characters must be of the same type, but this condition doesn't verify that 'a' is a lowercase letter.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: it doesn't check that 'b' >= 'A' or that 'a' <= 'Z', so mixed-type pairs might incorrectly pass. For example, if a='0' and b='Z', this condition could be true even though they are not both uppercase letters.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: it doesn't ensure that 'b' >= '0' or that 'a' <= '9', so non-digit characters could slip through.]
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
                    printf("%c",s[i]); // @@ [Missing else clause to print the '-' when expansion is not performed. In the current code, if check fails, nothing is printed for the '-' character, which causes it to be omitted from the output. According to the problem, the input should be output unchanged in such cases, meaning the '-' must still be printed.]
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