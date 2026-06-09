#include <stdio.h>
#include <string.h>
#define len 200
int main()
{
    char c;
    int i;
    char str[len];
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0'))
// @@ The condition `(str[i - 1] >= 'a' && str[i + 1] <= 'z')` is incorrect; it should check that both characters are within the same range (e.g., `str[i-1] >= 'a' && str[i-1] <= 'z' && str[i+1] >= 'a' && str[i+1] <= 'z'`). The current logic allows mismatched types like 'a' and 'F' to be expanded. Also, `((i - 1) != 0)` should be `(i > 0)` to properly handle the first character being '-'.
        {
            for (int j = 1; j < (str[i + 1] - str[i - 1]); j++)
            {
                printf("%c", str[i - 1] + j);
            }
        }
        else
            printf("%c", str[i]);
    }
    return 0;
}