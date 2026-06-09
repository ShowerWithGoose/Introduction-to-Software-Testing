#include <stdio.h>
#include <string.h>
char s[10000];
int judge(char a,char b)
{
    if(a<='9'&&a>='1'&&b<='9'&&b>='1'&&a<b) // @@ Error: The condition uses '1' instead of '0', so it excludes the digit '0' from expansion. Should be a>='0' and b>='0'.
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
                    printf("%c",'0'+j-'0'); // @@ Error: This expression incorrectly converts the character j to a digit. For letters, this will produce wrong output. Should directly print j as a character: printf("%c", j);
                }
            }
            else
            {
                printf("%c",s[i]); // @@ Error: This prints the '-' character directly, but the problem requires that when expansion is not performed, the '-' should be output unchanged. This is correct in logic, but note that the reference program also prints '-' in the else case, so this is not a bug per se. However, the buggy output shows a compilation error, which is not from this code. The actual error is in the judge function and the print loop.
            }
        }
    }
}
int main()
{
    scanf("%s",&s); // @@ Error: scanf with %s expects a pointer to the first element of the array, which is 's', not '&s'. Should be scanf("%s", s);
    expand(s);
    return 0;
}