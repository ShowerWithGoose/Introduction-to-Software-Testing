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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ [Logic error: This condition incorrectly handles characters adjacent to '-'. For input "a-c", when i=0 ('a'), s[i+1] is '-', so this condition is false. It falls through to the else-if or implicit else. If it falls to implicit else, nothing is printed. If it relies on the '-' handling, 'a' is printed there. However, the logic for non-'-' chars is flawed because it skips printing if a neighbor is '-', relying on the '-' case to print the neighbors. But the '-' case prints s[i-1] and s[i+1]. This leads to double printing or missing prints depending on flow. Specifically, for "a-c", i=0 ('a'): s[i+1]=='-', condition false. i=1 ('-'): enters else if. Prints 'a', expands, prints 'c'. i=2 ('c'): s[i-1]=='-', condition false. Implicit else does nothing. So 'c' is not printed again? Wait, the '-' case prints s[i+1] which is 'c'. So 'c' is printed. But what about the next char? In "a-c-g", after processing '-', i becomes 2. s[2] is 'c'. s[2-1] is '-'. Condition false. Implicit else. Nothing printed. Then i=3 is '-'. It processes 'c' and 'g'. It prints 'c' again. This causes duplication. The fundamental issue is that the loop iterates every character, and the logic for non-dash characters excludes those next to dashes, expecting the dash case to handle them. But the dash case handles its immediate neighbors. When the loop reaches the neighbor (e.g., 'c' at index 2), it is skipped by the first if, and not handled by the else-if (since it's not '-'). Thus it's lost unless the previous dash step printed it. But the previous dash step printed it as the *end* of the expansion. The next dash step will print it again as the *start* of the next expansion. This leads to duplication like "abcc...".]
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
                    printf("%c", s[i - 1]);
                    printf("-");
                    printf("%c", s[i + 1]);
                }
            }
        }
    }

    return 0;
}