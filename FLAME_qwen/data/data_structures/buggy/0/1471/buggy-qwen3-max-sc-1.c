#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k; // @@ [Using 'char' for loop variable 'k' can cause undefined behavior when incrementing beyond 127 (signed char overflow) or when dealing with values like 255 (unsigned); should use 'int' for safety and correctness in character range iteration.]
    int len, i;
    gets(line); // @@ [The function 'gets' is unsafe and deprecated; it was removed in C11 due to buffer overflow risks. However, the immediate error causing test failure is likely not this but the loop bounds and missing condition checks.]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs up to 'i == len', which accesses line[len] (the null terminator). When i == len and line[i] == '\0', if it were '-', it would access line[len+1] (out of bounds). More critically, when i=0 and line[0]=='-', it accesses line[-1] — undefined behavior. Also, the problem requires checking character types and validity before expansion, which is completely missing.]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [No validation that line[i-1] and line[i+1] are valid (i>0 and i<len-1), nor that they are same-type characters (e.g., both digits, both lowercase, etc.). This leads to incorrect expansions (e.g., expanding 'a-Z') or accessing out-of-bounds memory when '-' is at start/end. Also, 'k' as char may wrap around during loop.]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}