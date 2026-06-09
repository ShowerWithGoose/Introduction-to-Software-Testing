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
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ Error: When i is 0, s[i-1] accesses out-of-bounds memory; also the condition incorrectly skips characters that are part of a valid expansion range.
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1) // @@ Error: When i is 0, s[i-1] accesses out-of-bounds memory; also when '-' is at the start or end of the string, this causes undefined behavior.
                {
                    printf("%c", s[i - 1]); // @@ Error: This prints the left character before the expansion, but the left character should not be printed separately; the loop below already includes it.
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); // @@ Error: This prints the right character after the expansion, but the right character should not be printed separately; the loop should include it.
                }
                else
                {
                    printf("%c", s[i - 1]); // @@ Error: When i is 0, s[i-1] accesses out-of-bounds memory; also this prints the left character even if it was already printed in the previous iteration.
                    printf("-");
                    printf("%c", s[i + 1]); // @@ Error: This prints the right character even if it will be printed in the next iteration, causing duplication.
                }
            }
        }
    }

    return 0;
}