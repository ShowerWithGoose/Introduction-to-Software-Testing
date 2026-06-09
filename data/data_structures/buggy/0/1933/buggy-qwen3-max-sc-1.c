#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [The condition is incorrect: it should ensure both `a` and `b` are in the same category. This condition allows `a` to be any character >= 'a' and `b` <= 'z', even if `a` is uppercase or digit. It should be `a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && b > a`.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: condition does not verify that `a` is <= 'Z'. Should be `a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && b > a`.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: condition does not verify that `a` is <= '9'. Should be `a >= '0' && a <= '9' && b >= '0' && b <= '9' && b > a`.]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [`gets` is unsafe and deprecated; more critically, it may not be available in modern compilers, which could cause compilation errors. Use `fgets` instead. Also, the problem states input from keyboard, but `gets` doesn't handle newline safely.]
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
                else // @@ [Missing `else` branch for the case when `s[i] == '-'` but `check` fails. In this case, the '-' should be printed, but currently it is skipped entirely.]
                    printf("%c", s[i]); // This line is missing in the original code.
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