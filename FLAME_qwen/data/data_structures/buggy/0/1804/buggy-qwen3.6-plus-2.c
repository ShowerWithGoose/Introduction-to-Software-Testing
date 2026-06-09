#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int f(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b >= 'z' && a < b) // @@ Typo: 'b >= 'z'' should be 'b <= 'z''. This condition also duplicates the lowercase check; it likely intended to check uppercase letters [A-Z].
        return 1;
    else if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[1000] = { 0 };
    gets_s(s); // @@ gets_s is non-standard (C11 optional) and causes compilation errors on standard GCC/Linux environments; use fgets or gets instead.
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '-')
        {
            if (f(s[i - 1], s[i + 1]) == 0)
                printf("-");
            else
            {
                char i = s[i - 1]; // @@ Variable 'i' shadows the outer loop control variable 'i', causing incorrect array indexing and undefined behavior.
                for (i = s[i - 1];i <= s[i + 1];i++) // @@ Uses the shadowed 'char i' instead of the loop index. The loop range is also incorrect; it should start from s[i-1]+1 and end at s[i+1]-1 to avoid duplicating endpoints.
                    printf("%c", i);
            }
        }
        else
            printf("%c", s[i]);
    }
}