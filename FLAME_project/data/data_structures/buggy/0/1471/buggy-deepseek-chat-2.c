#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ The loop condition should be i < len, not i <= len, to avoid processing the null terminator.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Missing validation: does not check if characters around '-' are of the same type and in ascending order, leading to incorrect expansion (e.g., 'u' to 'B' should not be expanded).
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}