#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [The condition is incorrect: it should ensure both `a` and `b` are in the same category. This condition allows `a` to be any character >= 'a' and `b` <= 'z', which could mix types (e.g., 'A' and 'z'). It should be `a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && b > a`.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue as above: missing lower bound check for `b` and upper bound check for `a`. Should be `a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && b > a`.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: missing proper bounds. Should be `a >= '0' && a <= '9' && b >= '0' && b <= '9' && b > a`.]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [`gets` is unsafe and deprecated; more critically, it may not be available in modern compilers, leading to compilation errors. Use `fgets` instead. Also, this is likely the cause of the "gcc: not found" error being misinterpreted—actually, the real issue is that `gets` causes a compilation failure in strict environments.]
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