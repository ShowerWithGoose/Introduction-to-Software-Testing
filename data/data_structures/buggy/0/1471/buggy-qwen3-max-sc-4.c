#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs to 'i <= len', which accesses line[len] (null terminator) and potentially line[len+1] in loop body, causing out-of-bounds access when checking line[i+1]]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [No validation that '-' is between valid same-type characters (e.g., a-z, A-Z, 0-9); also accesses line[i-1] when i=0 (undefined behavior), and line[i+1] when i=len (out of bounds)]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}