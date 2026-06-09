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
                if (j(s[i - 1], s[i + 1]) == 1) @@ [When i=0, s[i-1] is invalid; when i is last index, s[i+1] is '\0', causing invalid expansion check]
                {
                    printf("%c", s[i - 1]); @@ [Prints previous char again even if it was already printed in prior iteration, causing duplication]
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); @@ [Prints next char here, but it will be printed again in next loop iteration, causing duplication]
                }
                else
                {
                    printf("%c", s[i - 1]); @@ [Same duplication issue: prints s[i-1] again even if already printed]
                    printf("-");
                    printf("%c", s[i + 1]); @@ [Prints s[i+1] now, but it will be printed again when i increments, leading to double output]
                }
            }
        }
    }

    return 0;
}