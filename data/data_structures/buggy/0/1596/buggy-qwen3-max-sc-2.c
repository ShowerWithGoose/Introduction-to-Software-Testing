#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ [The digit range should include '0', but it starts from '1', so inputs like '0-2' will not be expanded correctly.]
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
                    printf("%c",'0'+j-'0'); // @@ [This expression simplifies to just 'j', but more importantly, it incorrectly assumes all characters are digits. For letters, this corrupts output (e.g., 'a'+1 becomes '0' + ('b' - '0'), which is wrong).]
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
    scanf("%s",&s); // @@ [Passing &s (char (*)[10000]) instead of s (char*) to scanf with %s is technically incorrect and may cause undefined behavior, though many compilers accept it. Should be scanf("%s", s);]
    expand(s);
    return 0;
}