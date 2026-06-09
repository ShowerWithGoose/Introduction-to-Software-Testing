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
    for (int i = 0; i < strLength - 1; ++i)
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1)
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Error: This calculation is incorrect. It should be (str[i+1] - str[i-1] - 1) to represent the number of characters to insert (excluding the start and end), but the logic for shifting and inserting is flawed overall.
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ Error: This shift operation is incorrect because it uses strLength (original length) as the base, but the array size is fixed at 200. It also doesn't properly handle the case where multiple expansions occur, as strLength is not updated correctly.
            }
            for (int k = 0; k < backwardLength + 1; k++)
            {
                str[i + k] = str[i - 1] + 1 + k; // @@ Error: This overwrites the '-' and subsequent characters incorrectly. It should start at index i (the position of '-') and fill with the expanded characters, but the loop range and assignment are wrong.
            }
            str[strLength + backwardLength] = '\0'; // @@ Error: This updates the null terminator position, but strLength is not updated, so subsequent iterations use the old length, causing out-of-bounds access and incorrect behavior.
        }
    }
    printf("%s",str);
    return 0;
}