#include <stdio.h>
#include <string.h>
int main()
{
    char line[10086];
    char k;
    int len, i;
    gets(line);
    len = strlen(line);
    for (i = 0; i <= len; i++) // @@ The loop condition should be i < len. Using i <= len causes the loop to process the null terminator '\0' at index len, which results in printing an extra empty character or garbage at the end of the output. Additionally, accessing line[i+1] when i is len-1 (the last character) would be out of bounds if not handled, but the primary issue here causing the WA vs Expected difference (extra char) is the inclusion of the null terminator in the print loop.
    {
        if (line[i] == '-')
        {
            for (k = line[i - 1] + 1; k < line[i + 1]; k++)
            {
                printf("%c", k);
            }
        }
        else
            printf("%c", line[i]);
    }
    return 0;
}