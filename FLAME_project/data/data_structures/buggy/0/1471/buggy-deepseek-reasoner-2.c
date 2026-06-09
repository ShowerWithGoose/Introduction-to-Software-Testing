#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Loop goes up to len inclusive, causing the null terminator to be printed as an extra character.
    {
        if (line[i] == '-') // @@ Missing conditions: should check that characters on both sides are of same type and left < right; otherwise expansion should not be performed.
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ No bounds or validity checks; could access out-of-bounds indices and will expand even when conditions are not met.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}