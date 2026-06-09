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
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Missing validation: does not check if characters around '-' are of the same type and in ascending order, and does not handle cases where expansion should not occur (e.g., different types or descending order).
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}