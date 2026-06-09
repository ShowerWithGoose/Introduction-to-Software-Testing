#include <stdio.h>
#include <string.h>
#define len 200
int main()
{
    char c;
    int i;
    char str[len];
    gets(str); // @@ [gets() is unsafe and deprecated; use fgets() instead]
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-' && (str[i - 1] < str[i + 1]) && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')) && ((i - 1) != 0) && (str[i + 1] != '\0'))
        { // @@ [The condition ((i-1) != 0) incorrectly prevents expansion when the dash is at index 1; should be (i > 0) to check valid left character. Also, the range checks are incorrect: e.g., (str[i-1] >= 'a' && str[i+1] <= 'z') does not ensure both are lowercase letters; it should check both are within the same range, e.g., (str[i-1] >= 'a' && str[i-1] <= 'z' && str[i+1] >= 'a' && str[i+1] <= 'z')]
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