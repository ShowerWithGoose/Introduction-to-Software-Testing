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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ Accesses s[i-1] when i=0 causing out-of-bounds; logic incorrectly skips characters adjacent to '-', leading to duplicate output for consecutive expansions like 'a-c-g'
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    printf("%c", s[i - 1]); // @@ Unconditionally prints the start character of the expansion, causing duplication when the end of a previous expansion matches the start of the current one
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); // @@ Unconditionally prints the end character of the expansion, overlapping with the start character of the next expansion
                }
                else
                {
                    printf("%c", s[i - 1]); // @@ Prints character before '-' unconditionally, causing duplication with the end of a previously processed expansion
                    printf("-");
                    printf("%c", s[i + 1]); // @@ Prints character after '-' unconditionally, causing duplication
                }
            }
        }
    }

    return 0;
}