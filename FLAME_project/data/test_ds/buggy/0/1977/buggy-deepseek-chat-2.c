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
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Error: This calculation is incorrect. It should be the number of characters to insert, not the shift amount. For example, 'B'-'F' gives 4, but we need to insert 3 characters (C, D, E). The formula should be str[i+1] - str[i-1] - 1, and the shift logic is flawed.
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ Error: This shift operation is incorrect. It does not properly handle the expansion because backwardLength may be negative or miscalculated, and the loop overwrites data incorrectly.
            }
            for (int k = 0; k < backwardLength + 1; k++)
            {
                str[i + k] = str[i - 1] + 1 + k; // @@ Error: This overwrites the '-' and subsequent characters, but the shift above may not have created enough space, and the loop range is wrong. It should fill from i to i + (str[i+1] - str[i-1] - 1) - 1, but the shift logic is broken.
            }
            str[strLength + backwardLength] = '\0'; // @@ Error: The new length is not updated correctly. It should be strLength + (str[i+1] - str[i-1] - 1), but backwardLength is miscalculated.
        }
    }
    printf("%s",str);
    return 0;
}