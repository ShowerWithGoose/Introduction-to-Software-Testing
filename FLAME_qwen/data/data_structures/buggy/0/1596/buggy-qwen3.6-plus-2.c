#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ The digit range should include '0', so a>='1' and b>='1' should be changed to a>='0' and b>='0'.
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
            if(judge(s[i-1],s[i+1])) // @@ Missing boundary checks for array indices. When i=0, accessing s[i-1] causes out-of-bounds memory access. Should add i>0 && s[i+1]!='\0'.
            {
                for(j=s[i-1]+1;j<s[i+1];j++)
                {
                    printf("%c",'0'+j-'0');
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
    scanf("%s",&s); // @@ &s is of type char (*)[10000], but %s expects char *. It should be scanf("%s", s); to avoid type mismatch and potential undefined behavior.
    expand(s);
    return 0;
}