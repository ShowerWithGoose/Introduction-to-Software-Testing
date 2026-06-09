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
                    printf("%c", s[i - 1]); @@ // Printing s[i-1] here duplicates it because it was already printed in the previous iteration (unless it's the very first character). This causes repeated characters like 'c' in "abccdefg".
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); @@ // Similarly, printing s[i+1] here causes it to be printed again when the loop reaches that index later, unless special care is taken to skip it.
                }
                else
                {
                    printf("%c", s[i - 1]); @@ // Same duplication issue: s[i-1] may have already been printed.
                    printf("-");
                    printf("%c", s[i + 1]); @@ // And s[i+1] will likely be printed again when i advances.
                }
            }
        }
    }

    return 0;
}