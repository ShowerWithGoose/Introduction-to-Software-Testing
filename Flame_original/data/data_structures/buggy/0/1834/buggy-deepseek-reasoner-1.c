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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') @@ // Undefined behavior: accesses s[i-1] without bounds check for i=0. Logical error: condition prevents printing characters adjacent to '-', which is incorrect; should print all non-'-' characters unconditionally.
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1) @@ // Undefined behavior: accesses s[i-1] without bounds check; if i==0, s[-1] is invalid.
                {
                    printf("%c", s[i - 1]); @@ // Accesses s[i-1] without bounds check; also causes duplication of left endpoint (e.g., in "a-d-g").
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); @@ // Causes duplication of right endpoint (e.g., in "a-d-g").
                }
                else
                {
                    printf("%c", s[i - 1]); @@ // Accesses s[i-1] without bounds check.
                    printf("-");
                    printf("%c", s[i + 1]); @@ // Prints null terminator if i is last index.
                }
            }
        }
    }

    return 0;
}