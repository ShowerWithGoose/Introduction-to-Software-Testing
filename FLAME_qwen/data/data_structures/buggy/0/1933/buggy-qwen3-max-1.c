#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Incorrect condition: should also ensure 'a' is <= 'z'; current logic allows e.g. 'A' and 'm' to pass if b <= 'z' and b > a]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Incorrect condition: should also ensure 'a' is <= 'Z'; current logic allows e.g. '0' and 'K' to pass if b <= 'Z' and b > a]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Incorrect condition: should also ensure 'a' is <= '9'; current logic allows e.g. 'a' and '5' to pass if b <= '9' and b > a]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; also, some compilers/environments may not support it, leading to compilation or runtime issues]
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
                    printf("%c",s[i]); // @@ [Missing else branch to print '-' when check fails; currently, if check fails, nothing is printed for the '-' character]
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