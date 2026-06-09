#include <stdio.h>
#include <string.h>
int j(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[10000];
    while (gets(s) != NULL) // @@ [Use of unsafe and deprecated function 'gets' which may cause buffer overflow; also, in many modern environments, 'gets' is removed entirely, leading to compilation error]
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ [Accessing s[i - 1] when i=0 leads to out-of-bounds read (undefined behavior); also logic fails to handle non-'-' characters correctly when adjacent to '-']
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    printf("%c", s[i - 1]);
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]);
                }
                else
                {
                    printf("%c", s[i - 1]); // @@ [When '-' appears at start or end, s[i-1] or s[i+1] is invalid; also, this prints surrounding chars again even if they were already printed]
                    printf("-");
                    printf("%c", s[i + 1]); // @@ [Same issue: may access beyond string bounds or duplicate output]
                }
            }
        }
    }

    return 0;
}