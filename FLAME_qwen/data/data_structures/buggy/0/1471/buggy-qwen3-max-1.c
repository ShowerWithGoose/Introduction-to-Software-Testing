#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs to 'i <= len', which accesses line[len] (null terminator) and potentially line[len+1] in expansion logic, causing out-of-bounds access]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [Does not validate that '-' is between valid same-type characters (e.g., a-z, A-Z, 0-9), nor checks bounds (i-1 >= 0, i+1 < len), leading to undefined behavior and incorrect output for invalid cases]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}