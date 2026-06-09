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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition may skip last character and accessing str[i+1] when i = strLength-2 is safe, but logic fails to handle cases where '-' appears at beginning or end, leading to out-of-bounds access when i=0 and checking str[i-1]]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Accesses str[i-1] when i=0, which is str[-1] — undefined behavior / out-of-bounds read]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [If expansion is from 'a' to 'd', this gives 4-2=2, but should generate 2 intermediate chars ('b','c'), however logic of shifting and inserting is flawed and overwrites data incorrectly]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [Writes beyond original array bounds if backwardLength > 0 and strLength + backwardLength >= 200, causing buffer overflow]
            }
            for (int k = 0; k < backwardLength + 1; k++)
            {
                str[i + k] = str[i - 1] + 1 + k; // @@ [Overwrites the '-' and next char, but doesn't account for already shifted content; also, if backwardLength is negative (e.g., invalid range), loop runs incorrectly]
            }
            str[strLength + backwardLength] = '\0'; // @@ [Modifies string length but loop index 'i' continues without adjusting for new length, causing missed or double processing of characters]
        }
    }
    printf("%s",str);
    return 0;
}