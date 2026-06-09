#include <stdio.h>
#include <string.h>
int lowOrUp(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
        return 1;
    if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
        return 1;
    if (a >= '0' && a <= '9' && b >= '0' && b <= '9')
        return 1;
    return 0;
}
int main()
{
    char str[200];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int strLength = strlen(str);
    for (int i = 0; i < strLength - 1; ++i) @@ // Accessing str[i - 1] when i = 0 leads to out-of-bounds read (undefined behavior)
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) @@ // When i = 0, str[i - 1] is str[-1], which is invalid
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; @@ // Uses invalid str[i - 1] when i = 0; also logic error: should be (str[i+1] - str[i-1] - 1) characters to insert
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; @@ // May write beyond array bounds if backwardLength > 0 and strLength + backwardLength >= 200
            }
            for (int k = 0; k < backwardLength + 1; k++) @@ // backwardLength can be negative if str[i+1] - str[i-1] - 2 < 0, leading to unexpected loop behavior
            {
                str[i + k] = str[i - 1] + 1 + k; @@ // Overwrites the '-' and part of the following character incorrectly; also uses invalid str[i-1] when i=0
            }
            str[strLength + backwardLength] = '\0'; @@ // May write beyond array bounds; also doesn't update strLength for subsequent iterations, causing incorrect expansions in multi-range inputs
        }
    }
    printf("%s",str);
    return 0;
}