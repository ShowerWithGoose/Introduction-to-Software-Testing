#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k; // @@ [Using 'char' for loop variable 'k' can cause infinite loop or undefined behavior when incrementing beyond 127 (signed char overflow) or when dealing with values near CHAR_MAX; should use 'int' instead.]
    int len, i;
    gets(line); // @@ [Function 'gets' is unsafe and deprecated; may cause buffer overflow. However, the immediate error causing test failure is likely due to loop bounds and missing condition checks, not this line.]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs to 'i <= len', which accesses line[len] (null terminator) and line[len+1] in later logic, causing out-of-bounds read when '-' is at end; should be 'i < len'. Also, when i=0 and line[0]=='-', it accesses line[-1] which is invalid.]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [No validation that line[i-1] and line[i+1] are of same type (digit, upper, lower) or that line[i+1] > line[i-1]. Also, accesses line[i-1] when i=0 (undefined behavior) and line[i+1] when i=len (out-of-bounds).]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}