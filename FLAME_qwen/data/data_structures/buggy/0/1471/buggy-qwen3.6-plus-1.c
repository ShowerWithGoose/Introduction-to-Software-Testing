#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line); // @@ gets is deprecated and removed in C11, causing compilation errors in modern environments; use fgets instead.
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Loop condition i <= len accesses out-of-bounds index len (null terminator), should be i < len.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ 1. Accesses line[i-1] out of bounds when i=0. 2. Lacks validation for character types and order (line[i-1] < line[i+1]). 3. Fails to print '-' when expansion conditions are not met.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}