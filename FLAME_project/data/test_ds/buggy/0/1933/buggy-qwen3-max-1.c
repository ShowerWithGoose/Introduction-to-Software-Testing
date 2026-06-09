#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Incorrect condition: should check that both 'a' and 'b' are in the same category (e.g., both lowercase). Current condition only checks 'a' >= 'a' and 'b' <= 'z', which allows mixed cases like 'B' and 'e'.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: does not ensure 'b' is uppercase; e.g., 'B' (uppercase) and 'e' (lowercase) would incorrectly pass if 'e' <= 'Z' (which it isn't, but logic is flawed). Also, 'b>a' is redundant here since it's already required by problem, but main flaw is missing lower bound on 'b' and upper bound on 'a'.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: doesn't verify that 'b' >= '0' and 'a' <= '9'; could allow invalid digit ranges.]
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
                    printf("%c",s[i]); // @@ [Missing else clause to print '-' when expansion is not performed. In current code, if check fails, nothing is printed for '-', causing omission of '-'.]
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