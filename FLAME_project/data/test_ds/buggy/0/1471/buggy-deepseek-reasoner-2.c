#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++)  // @@ Loop should be i < len to avoid processing null terminator; otherwise prints extra character and may cause out-of-bounds access when i == len.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++)  // @@ Missing checks: should only expand if both characters are same type (lowercase, uppercase, or digit) and left < right. Also need boundary checks for i-1 and i+1.
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}