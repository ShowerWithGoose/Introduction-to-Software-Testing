#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k; // @@ [Using 'char' for loop variable 'k' can cause infinite loops or undefined behavior when incrementing beyond 127 (signed char overflow) or when dealing with values near CHAR_MAX. Should be 'int'.]
    int len, i;
    gets(line); // @@ [The function 'gets' is unsafe and deprecated; it was removed in C11. Use 'fgets' instead. Also, may cause buffer overflow if input exceeds array size minus one.]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs to 'i <= len', which accesses line[len] (null terminator) and potentially line[len+1] in the '-' handling logic, causing out-of-bounds read. Should be 'i < len'.]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [No validation that '-' is between valid same-type characters (e.g., a-z, A-Z, 0-9), or that line[i-1] < line[i+1]. Also, accesses line[i+1] even when i == len (out-of-bounds). Additionally, uses 'char' for loop counter which may overflow.]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}