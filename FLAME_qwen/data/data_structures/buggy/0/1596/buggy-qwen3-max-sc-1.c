#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ [The digit range should include '0', not start from '1'. This causes inputs like "0-2" to be incorrectly rejected.]
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
                    printf("%c",'0'+j-'0'); // @@ [This expression '0'+j-'0' simplifies to just j, but it's misleading and unnecessary. However, the real issue is that it works only for digits; for letters, it prints incorrect characters because it assumes all are digits. Should directly print 'j'.]
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
    scanf("%s",&s); // @@ [Passing &s (address of array) is technically acceptable in some compilers but incorrect style; should pass s (which decays to char*). However, this is not the cause of logical errors. The main issues are in judge() and expansion logic.]
    expand(s);
    return 0;
}