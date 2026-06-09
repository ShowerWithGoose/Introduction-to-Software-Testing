#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers that remove gets()]
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ [Loop runs to i == len, which accesses line[len] (null terminator) and possibly line[len+1] in next iteration if '-' is at end, causing out-of-bounds access]
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ [No validation that line[i-1] and line[i+1] are of same type or valid for expansion; also accesses line[-1] if '-' is first character]
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}