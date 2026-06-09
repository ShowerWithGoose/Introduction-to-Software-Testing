#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Error: Should also ensure b>='a' and a<='z'; lacking lower bound check for b. In the test case B-e this condition fails, but for different types like a and Z it would incorrectly return 1.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Error: Should also ensure b>='A' and a<='Z'; same issue as above.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Error: Should also ensure b>='0' and a<='9'; same issue.]
        return 1;
    return 0;
}
int main()
{
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        if(i>=1&&i<strlen(s)-1)
        {
            if(s[i]=='-')
            {
                if(check(s[i-1],s[i+1]))
                {
                    for(char a=s[i-1]+1;a<s[i+1];a++)
                        printf("%c",a);
                }
                // @@ [Error: Missing else clause to print the dash when check fails. The original dash should be output as-is, but the program prints nothing, causing the dash to be omitted. For input B-e, this results in output Be instead of B-e.]
            }
            else
            {
                printf("%c",s[i]);
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}