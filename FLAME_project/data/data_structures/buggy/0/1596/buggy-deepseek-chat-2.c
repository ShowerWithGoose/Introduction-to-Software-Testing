#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ Error: The condition a>='1' excludes the digit '0', but the problem requires processing digits in the range [0-9]. Should be a>='0' and b>='0'.
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
                    printf("%c",'0'+j-'0'); // @@ Error: This expression is incorrect for printing characters. For digits, it should be printf("%c", j); because j is already the ASCII value. For letters, it would also be j. The current expression '0'+j-'0' simplifies to j, but it's confusing and unnecessary. However, the main issue is that for digits, j is an integer ASCII value, and printing j directly works. But the real bug is that the loop condition j < s[i+1] uses the ASCII value of the next character, which is correct, but the printf expression is redundant and could cause confusion. The actual error causing wrong output is in the judge function's digit range.
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