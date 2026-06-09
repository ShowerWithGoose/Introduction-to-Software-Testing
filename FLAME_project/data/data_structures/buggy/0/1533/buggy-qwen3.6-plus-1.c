#include<stdio.h>
#include<string.h>
char kz(char s[])
{
    char c[100];
    int j=0; 
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9')) // @@ [The original condition used strict less than '<' for the upper bound ('z', 'Z', '1') and incorrect character '1' instead of '9' for digits. This prevented valid expansions like '0-8' (where '8' is not < '9' if it were correct, but originally checked against '1') or 'a-z'. The upper bound should be inclusive (<=) to allow the full range, and the digit check should compare against '9'.]
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]) // @@ [The original loop condition was c[j] < s[i+1]-1, which stopped one character too early. For example, expanding '0-8' starts at '1'. The loop should continue printing until the character reaches '8' (s[i+1]). The condition c[j] < s[i+1] ensures that when c[j] becomes equal to s[i+1], the loop stops, having printed all intermediate characters including the one just before s[i+1]. However, looking at the logic: it prints c[j], then increments. If we want to print up to s[i+1]-1, the condition c[j] < s[i+1] is correct because inside the loop we increment j and calculate next. Wait, let's trace.
            // Start: c[0] = '1'. Print '1'.
            // While '1' < '8':
            //   j becomes 1. c[1] = '2'. Print '2'.
            //   ...
            //   When c[j] is '7'. Print '7'.
            //   While '7' < '8': True.
            //   j becomes k. c[k] = '8'. Print '8'.
            //   While '8' < '8': False. Loop ends.
            // This prints 12345678. Correct.
            // The original code had c[j] < s[i+1]-1.
            // Start: c[0] = '1'. Print '1'.
            // While '1' < '7': True.
            //   j=1, c[1]='2'. Print '2'.
            //   ...
            //   When c[j] is '6'. Print '6'.
            //   While '6' < '7': True.
            //   j=k, c[k]='7'. Print '7'.
            //   While '7' < '7': False. Loop ends.
            // This prints 1234567. Missing '8'.
            // So the condition needs to be c[j] < s[i+1].
            {
                j++;
                c[j]=c[j-1]+1;
                printf("%c",c[j]);
            }
            j++;
        }
        else
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
    }
}
int main()
{
    char s[100];
    gets(s);
    kz(s);
    return 0;
}