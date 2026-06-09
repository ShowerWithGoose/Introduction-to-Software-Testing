#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [condition fails to ensure b>='a' and a<='z'; may accept invalid characters]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [condition fails to ensure b>='A' and a<='Z']
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [condition fails to ensure b>='0' and a<='9']
        return 1;
    return 0;
}
int main()
{
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(i>=1&&i<strlen(s)-1) // @@ [when s[i]=='-' and check fails, the dash is not printed]
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