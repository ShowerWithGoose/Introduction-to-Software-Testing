#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) @@ // Error: does not ensure both characters are of the same type; should also check a<='z' and b>='a'
        return 1;
    if(a>='A'&&b<='Z'&&b>a) @@ // Error: same issue, allows cross-type like 'A' and 'z'
        return 1;
    if(a>='0'&&b<='9'&&b>a) @@ // Error: same issue, improperly validates
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
            } @@ // Error: when check fails, the '-' character is not printed; missing else clause to handle the false case
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