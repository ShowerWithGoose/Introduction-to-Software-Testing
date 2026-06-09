#include <stdio.h>
#include <string.h>
char s[1000001];
int check(char a,char b)
{
    if(a>='a'&&b<='z'&&b>a) // @@ [Logic error: The condition `a>='a'` only checks the lower bound for lowercase, missing `a<='z'`. More importantly, it fails to ensure `a` and `b` are of the SAME type. For input 'B-e', 'B' is not >= 'a', so this fails. But for 'a-R', 'a'>='a' is true, 'R'<='z' is true, 'R'>'a' is true, so it would incorrectly return 1. The check must verify both chars are in the same range [a-z], [A-Z], or [0-9].]
        return 1;
    if(a>='A'&&b<='Z'&&b>a) // @@ [Logic error: Similar to above, `a>='A'` misses upper bound `a<='Z'`. It doesn't strictly enforce same type if ranges overlap or if logic is flawed. Specifically, it allows cases where types might mismatch if bounds aren't strict. However, the primary issue in the test case B-e is handled by the fact that 'B' is not >= 'a'. But wait, 'B' IS >= 'A'. And 'e' IS <= 'Z'? No, 'e' > 'Z'. So this returns 0. This specific check is actually okay for B-e because 'e' is not <= 'Z'. But the logic is still fragile/incorrect for other cases like 'a-R' if the first check catches it. The main bug is likely elsewhere or in how the expansion is printed vs original chars.]
        return 1;
    if(a>='0'&&b<='9'&&b>a) // @@ [Logic error: Missing `a<='9'`. Same pattern of incomplete boundary checking.]
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
                else
                {
                     // @@ [Missing else block: If check fails, the '-' and the surrounding characters should be printed as they are. Currently, if check fails, nothing is printed for the '-', and the surrounding chars are printed in their respective iterations. However, the previous char s[i-1] was already printed in the previous iteration (i-1). The current char '-' is skipped. The next char s[i+1] will be printed in iteration i+1. So for 'B-e', if check fails, 'B' is printed at i=0. At i=1 ('-'), check fails, nothing printed. At i=2 ('e'), it goes to else branch of outer if? No, i=2 is strlen-1? If len=3, indices 0,1,2. i=2 is not < strlen-1 (2<2 is false). So it goes to final else. Prints 'e'. Output 'Be'. Expected 'B-e'. The '-' is missing.]
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