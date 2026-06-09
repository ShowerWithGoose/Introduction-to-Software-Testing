#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ Logical error: missing upper bound check for 'a' (a<='z') and lower bound check for 'b' (b>='a'). This fails to ensure both characters are strictly within the same valid range.
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ Logical error: missing upper bound check for 'a' (a<='Z') and lower bound check for 'b' (b>='A').
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ Logical error: missing upper bound check for 'a' (a<='9') and lower bound check for 'b' (b>='0').
        return 1;
    return 0;
}
int main()
{
    gets(s); // @@ Compilation error in modern C (C11 and later): 'gets' has been removed from the standard library due to security vulnerabilities; use 'scanf("%s", s)' or 'fgets(s, sizeof(s), stdin)' instead.
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