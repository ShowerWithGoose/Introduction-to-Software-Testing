#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a)
        return 1;
    if(a>='A'&&b<='Z'&&b>a)
        return 1;
    if(a>='0'&&b<='9'&&b>a)
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
                else // @@ Missing handling for the case where check returns 0: should output the '-' character and the preceding character if not already output
                {
                    printf("%c",s[i]); // @@ This line incorrectly prints only the '-' when check fails, but should also print the preceding character and the '-' to preserve the original input
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