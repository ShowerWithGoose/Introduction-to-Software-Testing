#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Error: loop should be i < len; otherwise accesses line[len] (null) and line[len+1] out of bounds, and when i=0, line[i-1] is undefined.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Error: no validation that characters exist and are of same type (digit, uppercase, lowercase) with c[i-1] < c[i+1]; also fails to output '-' when expansion condition not met.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}