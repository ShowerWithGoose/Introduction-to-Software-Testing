#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Error: Loop condition should be i < len, not i <= len, to avoid accessing out-of-bounds when i equals len.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Error: No check that both sides of '-' are valid characters of the same type and that the right character is greater than the left; also missing handling for cases where expansion should not occur (e.g., different types or left >= right).
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}