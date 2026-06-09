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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition stops too early; should allow checking up to i = strLength - 2 to safely access str[i+1], but more critically, the logic inside modifies the string and its length during iteration, causing missed expansions like in "B-F" after processing "a-u"]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Accesses str[i-1] when i=0, leading to undefined behavior; also fails to check that str[i+1] > str[i-1], violating problem requirement]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between str[i-1] and str[i+1] is (str[i+1] - str[i-1] - 1), so inserted chars count is (str[i+1] - str[i-1] - 1), but this computes one less]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [Writes beyond current string bounds before updating strLength; also, shifting logic is flawed because it doesn't account for multiple expansions or updated length properly]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [Due to incorrect backwardLength, this loop doesn't generate all needed characters; e.g., for 'B' to 'F', it should output C,D,E,F but may miss some]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [Updates null terminator but doesn't update strLength for subsequent iterations, causing later parts of the string (like "-F") to be skipped or misprocessed]
        }
    }
    printf("%s",str);
    return 0;
}