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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-')
            {
                printf("%c", s[i]); // @@ This condition incorrectly excludes characters that are part of a valid expansion range. For example, in "a-c-g", when i=2 (character 'c'), s[i+1] is '-', so 'c' is skipped, but it should be printed as part of the expansion from a-c. The logic should handle printing characters that are not '-' or are part of an expansion differently.
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    printf("%c", s[i - 1]); // @@ This prints the left character again, causing duplication. For "a-c", it prints 'a' then the expansion 'b' then 'c', but the left character 'a' was already printed (or should be handled). The expansion loop below also prints the left character via s[i-1]+j+1 starting from j=0, which adds an extra character. The correct approach is to print only the missing characters between s[i-1] and s[i+1], not including the endpoints.
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1); // @@ This loop prints characters from s[i-1]+1 to s[i+1]-1, but combined with the previous printf, it duplicates s[i-1] and s[i+1] are printed elsewhere, leading to extra characters. For "a-c", it prints 'a' then 'b' then 'c' (from the loop? Actually loop prints 'b' only, but the extra printf adds 'a', and later the next iteration may print 'c' again). The logic is flawed.
                    }
                    printf("%c", s[i + 1]); // @@ This prints the right character, but it may be printed again in the next iteration when i increments, causing duplication. For "a-c", after processing '-', i becomes 2 (pointing to 'c'), and the next loop iteration prints 'c' again, resulting in "abcc".
                }
                else
                {
                    printf("%c", s[i - 1]); // @@ This prints the left character, but it may have already been printed in a previous iteration, causing duplication. For "0-A", s[i-1] is '0', which was printed earlier, so it appears twice.
                    printf("-");
                    printf("%c", s[i + 1]); // @@ This prints the right character, but it may be printed again in the next iteration, causing duplication.
                }
            }
        }
    }

    return 0;
}