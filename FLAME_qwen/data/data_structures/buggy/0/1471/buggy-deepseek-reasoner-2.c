#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Loop includes null terminator; should be i < len to avoid printing '\0' and out-of-bounds access.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Multiple issues: no bounds check (i-1 or i+1 may be invalid), no validation of character types/ranges, no condition that expansion is allowed, and '-' is not printed when expansion is invalid. Also, loop may produce incorrect characters.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}