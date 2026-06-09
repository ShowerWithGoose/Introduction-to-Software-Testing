#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ [The digit range should include '0', but this condition excludes '0' by using a>='1'. This causes cases like '0-8' to fail because '0' is not in ['1','9'].]
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
                    printf("%c",'0'+j-'0'); // @@ [This conversion '0'+j-'0' simplifies to just j, but it's misleading and incorrect when j is not a digit. For letters, this will produce wrong characters. It should directly print (char)j.]
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
    scanf("%s",&s); // @@ [Using &s is technically incorrect; it should be s since s is already an array (decays to pointer). While it may work in practice due to how arrays are passed, it's semantically wrong and could cause issues with some compilers or static analyzers. However, the primary bugs are in judge() and expand().]
    expand(s);
    return 0;
}