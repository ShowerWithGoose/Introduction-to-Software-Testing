#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Incorrect condition: should also ensure 'a' <= b and 'a' >= 'a'; current logic allows cases like a='0', b='z' to pass if b>a, because it doesn't verify that both are in the same category]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: missing check that 'b' >= 'A' and 'a' <= 'Z'; e.g., a='0', b='Z' could incorrectly satisfy this if b>a]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: missing check that 'b' >= '0' and 'a' <= '9'; e.g., a='a', b='9' might pass if b>a numerically but types differ]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, many compilers remove 'gets' entirely, leading to compilation error]
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