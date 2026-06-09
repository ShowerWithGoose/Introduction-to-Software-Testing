#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ [The digit range should include '0', but this condition excludes '0' by using >= '1'. This causes inputs like "0-2" to be incorrectly rejected.]
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
                    printf("%c",'0'+j-'0'); // @@ [This expression simplifies to just 'j', but it's unnecessarily complex and misleading. More critically, it works only for digits; for letters, it corrupts output because '0'+j-'0' == j, but the intent may have been different. However, since j is already the correct ASCII value, this line accidentally works—but the logic is confusing and error-prone. The real issue is that the loop variable j is reused from outer scope, causing potential undefined behavior due to modification of loop control variable.]
                }
            }
            else
            {
                printf("%c",s[i]);
            }
        }
    }
}
int main()
{
    scanf("%s",&s); // @@ [Passing &s (char (*)[10000]) instead of s (char *) to scanf with %s is technically incorrect, though many compilers accept it. It should be scanf("%s", s);]
    expand(s);
    return 0;
}