#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ [Digits should include '0', but condition uses '1' as lower bound, so '0' is incorrectly excluded]
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
                    printf("%c",'0'+j-'0'); // @@ [Incorrect character printing logic: '0'+j-'0' simplifies to j, but j is an ASCII value; should print (char)j directly]
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
    scanf("%s",&s); // @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]
    expand(s);
    return 0;
}