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
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ The condition ((i - 1) != 0) incorrectly prevents expansion when the '-' is at index 1 (i.e., the range starts at the first character); it should be i > 0. Additionally, the type checking logic ((str[i-1] >= 'a' && str[i+1] <= 'z') || ...) fails to ensure both characters are of the same type, as it only checks independent bounds rather than verifying both fall within the same specific range.
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