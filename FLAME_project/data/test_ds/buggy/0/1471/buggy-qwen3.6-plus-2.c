#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Loop condition should be i < len to avoid processing the null terminator '\0' at the end of the string.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Missing validation: expansion should only occur if line[i-1] and line[i+1] are of the same type (both lowercase, uppercase, or digits) and line[i-1] < line[i+1]. Otherwise, '-' should be printed.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}