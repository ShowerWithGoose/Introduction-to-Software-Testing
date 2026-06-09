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
    for (int i = 0; i < strLength - 1; ++i) // @@ Error: i starts at 0, causing str[i-1] to access out-of-bounds memory when i=0. Should start from 1.
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ Error: Missing condition to check if str[i+1] > str[i-1] as required by the problem statement.
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Error: Calculation is off by one. Should be -1 to correctly compute the number of characters to insert between the bounds.
            int backNum = strLength - i - 1; // @@ Error: Should be strLength - i to include the null terminator during the shift operation.
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j];
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ Error: Loop bound is off by one. Should be k < backwardLength to avoid overwriting the shifted character and producing duplicate output.
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0';
        }
    }
    printf("%s",str);
    return 0;
}