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
                    printf("%c",'0'+j-'0'); // @@ [This expression '0'+j-'0' simplifies to just j, but it's misleading and unnecessary. However, the real issue is that j is an int used as a char, which is okay, but the logic fails for letters because this conversion only makes sense for digits. For letters, it prints incorrect characters. The correct approach is to print (char)j directly.]
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
    scanf("%s",&s); // @@ [Passing &s (char (*)[10000]) to scanf with %s expects char*, which is technically acceptable in practice but not strictly correct; however, the bigger issue is lack of input length safety. But the compilation error mentioned in the problem is likely due to environment, not this line. However, the actual functional errors are elsewhere.]
    expand(s);
    return 0;
}