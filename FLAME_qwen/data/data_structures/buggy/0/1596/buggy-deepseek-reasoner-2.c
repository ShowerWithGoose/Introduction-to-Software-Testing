#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ Error: digit range should include '0' instead of '1', and missing condition (b-a >= 2) to require at least one character between
    {
        return 1;
    }
    else if(a<='z'&&a>='a'&&b<='z'&&b>='a'&&a<b) // @@ Error: missing condition (b-a >= 2) to require at least one character between
    {
        return 1;
    }
    else if(a<='Z'&&a>='A'&&b<='Z'&&b>='A'&&a<b) // @@ Error: missing condition (b-a >= 2) to require at least one character between
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
    scanf("%s",&s);
    expand(s);
    return 0;
}