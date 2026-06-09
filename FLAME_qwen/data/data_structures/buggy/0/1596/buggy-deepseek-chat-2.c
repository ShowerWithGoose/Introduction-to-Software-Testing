#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ Error: The condition should be a>='0' instead of a>='1' and b>='0' instead of b>='1' to include digit '0'. Also, the range check for digits should be a>='0' && a<='9' and b>='0' && b<='9'.
    {
        return 1;
    }
    else if(a<='z'&&a>='a'&&b<='z'&&b>='a'&&a<b)
    {
        return 1;
    }
    else if(a<='Z'&&a>='A'&&b<='Z'&&b>='A'&&a<b)
    {
        return 1;
    }
    return 0;
}
void expand(char s[])
{
    int i,j;
    char k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else 
        {
            if(judge(s[i-1],s[i+1]))
            {
                for(j=s[i-1]+1;j<s[i+1];j++)
                {
                    printf("%c",'0'+j-'0'); // @@ Error: This expression is incorrect. It should simply be printf("%c", j); because j is already the character code. The current expression '0'+j-'0' simplifies to j, but the logic is confusing and may cause issues if j is not a digit.
                }
            }
            else
            {
                printf("%c",s[i]); // @@ Error: Should print the '-' character directly, but using s[i] is correct here. However, the logic is fine.
            }
        }
    }
}
int main()
{
    scanf("%s",&s); // @@ Error: scanf with %s expects a pointer to the first element, so &s is incorrect; it should be s (without &) or &s[0].
    expand(s);
    return 0;
}