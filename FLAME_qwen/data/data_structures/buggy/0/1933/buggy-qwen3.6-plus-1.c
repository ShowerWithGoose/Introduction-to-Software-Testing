#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Logical error: Condition incorrectly checks ranges. It should verify both a and b are within [a-z], e.g., a>='a' && a<='z' && b>='a' && b<='z' && b>a.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Logical error: Condition incorrectly checks ranges. It should verify both a and b are within [A-Z], e.g., a>='A' && a<='Z' && b>='A' && b<='Z' && b>a.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Logical error: Condition incorrectly checks ranges. It should verify both a and b are within [0-9], e.g., a>='0' && a<='9' && b>='0' && b<='9' && b>a.]
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ [Compilation error: gets() is removed in the C11 standard and causes compilation failure in modern compilers. Use scanf("%s", s) or fgets().]
    for(int i=0;i<strlen(s);i++)
    {
        if(i>=1&&i<strlen(s)-1)
        {
            if(s[i]=='-')
            {
                if(check(s[i-1],s[i+1])) // @@ [Logical error: When check returns false, the '-' character is not printed. An else branch is needed to output '-' when expansion conditions are not met.]
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