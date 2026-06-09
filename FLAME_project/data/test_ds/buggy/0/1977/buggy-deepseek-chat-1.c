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
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Error: This calculation is incorrect. It should be str[i+1] - str[i-1] - 1 to represent the number of characters to insert (excluding the start and end). The current value is off by one, causing the expansion to be incomplete.
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j];
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ Error: The loop condition should be k < backwardLength (not +1) to correctly fill the expanded characters. With +1, it writes one extra character, potentially overwriting the next part of the string.
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ Error: The new length should be strLength + backwardLength + 1 (since backwardLength is the number of inserted characters minus the dash). This miscalculation leads to an incorrect null terminator placement.
        }
    }
    printf("%s",str);
    return 0;
}