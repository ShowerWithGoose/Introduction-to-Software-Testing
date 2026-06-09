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
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0')) // @@ The condition for checking character ranges is incorrect. It should ensure both characters are within the same range (e.g., both lowercase, both uppercase, or both digits), but the current conditions like (str[i-1] >= 'a' && str[i+1] <= 'z') allow mismatched types (e.g., 'a' and 'z' are fine, but 'a' and 'B' would also pass incorrectly). Also, the check ((i-1) != 0) is wrong; it should be (i > 0) to prevent accessing str[-1] when i=0.
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