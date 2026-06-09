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
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ The condition ((i - 1) != 0) incorrectly prevents expansion when '-' is at index 1 (e.g., "a-u"), it should be i > 0. Additionally, the type checking logic is flawed as it allows cross-type ranges; both characters must be verified to be within the same specific range.
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