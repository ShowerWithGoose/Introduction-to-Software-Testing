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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') @@ // This condition incorrectly skips printing characters that are adjacent to '-', leading to missing or duplicated output. For example, when processing "a-c-g", the 'c' is printed both as the end of "a-c" and the start of "c-g", causing duplication.
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    printf("%c", s[i - 1]); @@ // The character before '-' is printed here, but it may have already been printed in the previous iteration, causing duplication (e.g., 'c' in "a-c-g").
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); @@ // The character after '-' is printed here, but will be printed again in the next iteration when i reaches that position, causing duplication.
                }
                else
                {
                    printf("%c", s[i - 1]); @@ // Same issue: s[i-1] may have already been printed, and s[i+1] will be printed again later.
                    printf("-");
                    printf("%c", s[i + 1]);
                }
            }
        }
    }

    return 0;
}