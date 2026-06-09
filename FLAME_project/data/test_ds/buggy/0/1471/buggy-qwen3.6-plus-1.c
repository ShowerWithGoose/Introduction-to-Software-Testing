#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Loop condition should be i < len to avoid processing the null terminator and potential out-of-bounds access.
    {
        if (line[i] == '-') // @@ Missing validation to ensure both surrounding characters are of the same type and the left character is strictly less than the right character.
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Expands unconditionally without checking validity; also fails to output '-' when expansion conditions are not met.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}