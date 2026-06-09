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
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Error: This calculation is incorrect. It should be (str[i+1] - str[i-1] - 1) to represent the number of characters to insert between the two endpoints, but the logic for shifting and inserting is fundamentally flawed.
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ Error: This shift operation is incorrect because it modifies the string in place without properly handling the expansion, leading to buffer overflow and incorrect results.
            }
            for (int k = 0; k < backwardLength + 1; k++)
            {
                str[i + k] = str[i - 1] + 1 + k; // @@ Error: This overwrites the '-' and subsequent characters incorrectly, and the loop bound should be backwardLength + 1, but the logic for inserting the expanded characters is wrong.
            }
            str[strLength + backwardLength] = '\0'; // @@ Error: This incorrectly updates the string length, but the loop variable 'i' and 'strLength' are not updated, causing the loop to continue with incorrect indices.
        }
    }
    printf("%s",str);
    return 0;
}