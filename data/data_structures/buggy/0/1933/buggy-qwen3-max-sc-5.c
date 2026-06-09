#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Incorrect condition: should also check that 'a' <= 'z' and 'b' >= 'a'; current logic allows cases like a='0', b='b' to pass if b>a, because it only checks a>='a' and b<='z' independently without ensuring both are in the same category]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Same issue: missing check that 'b' >= 'A' and 'a' <= 'Z'; may incorrectly allow mixed-type ranges]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Same issue: missing check that 'b' >= '0' and 'a' <= '9'; may allow invalid digit-letter combinations]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, some compilers/environments may not support it, leading to compilation or runtime errors]
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
                else // @@ [Missing else to print the '-' when check fails; as per problem, if expansion conditions aren't met, output input unchanged, including the '-']
                    printf("%c", s[i]);
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