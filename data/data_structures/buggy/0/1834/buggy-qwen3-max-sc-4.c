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
    while (gets(s) != NULL)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') @@ [Accessing s[i - 1] when i=0 leads to out-of-bounds read (undefined behavior)]
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1) @@ [When i=0, s[i-1] is invalid; when i is last index, s[i+1] is '\0', leading to invalid comparisons]
                {
                    printf("%c", s[i - 1]); @@ [This prints the previous character again, causing duplication since it was already printed in prior iteration]
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); @@ [This prints the next character now, but it will be printed again in the next loop iteration, causing duplication]
                }
                else
                {
                    printf("%c", s[i - 1]); @@ [Same duplication issue: s[i-1] already printed earlier]
                    printf("-");
                    printf("%c", s[i + 1]); @@ [s[i+1] will be printed again when i increments, causing duplication]
                }
            }
        }
    }

    return 0;
}