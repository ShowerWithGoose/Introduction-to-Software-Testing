#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k; // @@ [Using 'char' for loop counter 'k' can cause overflow or undefined behavior when incrementing beyond 127 (for signed char) or 255 (for unsigned char), especially when expanding ranges like 'a' to 'z'. Should use 'int' instead.]
    int len, i;
    gets(line); // @@ [The function 'gets' is unsafe and deprecated; it can cause buffer overflow. However, the immediate error causing test failure is likely due to unhandled edge cases like '-' at start/end or mismatched types, not compilation. But note: in modern compilers, 'gets' may cause compilation error or warning leading to failure if treated as error.]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs to 'i <= len', which accesses line[len] (null terminator) and potentially line[len+1] in expansion logic, causing out-of-bounds read when '-' is at last position. Should be 'i < len'.]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [No validation that line[i-1] and line[i+1] are of same type (both digits, both uppercase, or both lowercase) or that line[i-1] < line[i+1]. Also, if i==0, line[i-1] is out-of-bounds. Similarly, if i==len-1, line[i+1] is null terminator or beyond. This leads to undefined behavior and incorrect output.]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}