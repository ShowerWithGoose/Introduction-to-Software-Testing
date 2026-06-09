#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Incorrect condition: should also check that 'a' <= 'z' and 'b' >= 'a'; current logic allows cases like a='0', b='b' to pass if b>a, because it doesn't ensure both are in the same category]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: missing lower bound check for 'b' and upper bound check for 'a'; e.g., a='z', b='B' might incorrectly pass if b>a due to ASCII values]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: does not verify that 'b' >= '0' and 'a' <= '9'; could allow mixed-type ranges]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause buffer overflow. Also, some compilers/environments disable gets(), leading to compilation error. Should use fgets() instead.]
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
                {
                    printf("%c",s[i]); // @@ [Missing else clause to print '-' when check fails; currently, if check fails, nothing is printed for '-', causing omission of '-' in output]
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