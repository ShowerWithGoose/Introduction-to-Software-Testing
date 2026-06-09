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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ [Logic error: This condition incorrectly handles characters adjacent to '-'. For input "a-c", when i=0 ('a'), s[i+1] is '-', so this condition is false. It falls through to the else-if or implicit else. If it falls to implicit else, nothing is printed. If it relies on the '-' handling, 'a' is printed there. However, the logic for non-dash characters that are neighbors of dash is missing or handled incorrectly leading to double printing or skipping. Specifically, the condition `s[i-1] != '-'` accesses out of bounds when i=0. More importantly, the logic structure fails to correctly skip characters that have already been processed as part of an expansion or a literal dash sequence.]
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    printf("%c", s[i - 1]); // @@ [Logical Error: The character before the dash (s[i-1]) was likely already printed in a previous iteration if it wasn't caught by the first if, or if it was caught by the first if, it's printed here again. In the specific failing case "a-c-g...", 'a' is printed. Then when i=1 ('-'), it prints 'a' again. This causes duplication. The code needs to ensure that characters involved in an expansion or literal dash print are not printed multiple times.]
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]);
                }
                else
                {
                    printf("%c", s[i - 1]); // @@ [Logical Error: Similar to above, s[i-1] is printed here. If s[i-1] was already printed as a "normal" character in the previous iteration (because the check `s[i+1] != '-'` failed but `s[i-1] != '-'` might have passed or failed depending on logic), it results in duplication. For "a-c", 'a' is printed. Then at '-', 'a' is printed again.]
                    printf("-");
                    printf("%c", s[i + 1]);
                }
            }
        }
    }

    return 0;
}