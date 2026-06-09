#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ Condition should verify both a and b are lowercase (a>='a' && a<='z' && b>='a' && b<='z' && b>a)
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ Condition should verify both a and b are uppercase (a>='A' && a<='Z' && b>='A' && b<='Z' && b>a)
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ Condition should verify both a and b are digits (a>='0' && a<='9' && b>='0' && b<='9' && b>a)
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
                if(check(s[i-1],s[i+1])) // @@ Missing else to print '-' when check fails
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