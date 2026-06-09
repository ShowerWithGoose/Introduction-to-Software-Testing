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
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Error: No check for valid range or same type of characters around '-', and no check that line[i-1] < line[i+1]; also, when i is 0, line[i-1] accesses out-of-bounds.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}