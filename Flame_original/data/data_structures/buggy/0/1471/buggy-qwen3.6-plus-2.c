#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line); // @@ gets() is removed in the C11 standard and causes a compilation error in modern environments; also unsafe due to buffer overflow risk.
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ Loop bound i <= len causes out-of-bounds access when evaluating line[i+1] at i = len-1; should be i < len.
    {
        if (line[i] == '-') // @@ Missing boundary checks for i > 0 and i < len-1, leading to undefined behavior when accessing line[i-1] or line[i+1].
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++) // @@ Fails to verify that line[i-1] and line[i+1] are of the same type and that line[i-1] < line[i+1] as required; unconditionally expands and accesses invalid memory if i=0.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}