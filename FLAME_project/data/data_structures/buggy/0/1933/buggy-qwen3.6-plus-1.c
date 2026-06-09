#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Logic error: The condition `a>='a'` only checks the lower bound for lowercase, missing `a<='z'`. More importantly, it fails to ensure `a` and `b` are of the SAME type. For input 'B-e', 'B' is not >= 'a', so this fails. But for 'a-Z', 'a'>='a' is true, 'Z'<='z' is true, 'Z'>'a' is false. Wait, the main issue is that it doesn't check if both are uppercase or both are digits separately in a way that prevents mixing. Actually, the specific failure for 'B-e' is: 'B' is not >= 'a', so first if fails. 'B' >= 'A' is true, 'e' <= 'Z' is false. So second if fails. 'B' >= '0' is true, 'e' <= '9' is false. So it returns 0. This seems correct for 'B-e'. Let's re-read the buggy output. Input 'B-e', Output 'Be'. Expected 'B-e'. The code prints 'B' (i=0, else branch). Then i=1, s[1]=='-'. check('B','e') returns 0. So the loop `for(char a=s[i-1]+1;a<s[i+1];a++)` is skipped. But the code DOES NOT print the '-' character itself when expansion does not happen. It only prints the characters around it in other iterations. When i=1, it enters the `if(s[i]=='-')` block. If check fails, it does nothing. It doesn't print '-'. Then i=2, s[2]='e'. It enters the `else` block (since s[2]!='-') and prints 'e'. Result: 'Be'. The error is that when expansion is not performed, the '-' character is lost.]
        return 1;
    if(a>='A'&&b<='Z'&&b>a)
        return 1;
    if(a>='0'&&b<='9'&&b>a)
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
                else // @@ [Missing else block: When check fails, the '-' character should be printed to preserve the original string structure, otherwise it is omitted from the output.]
                {
                    printf("-");
                }
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