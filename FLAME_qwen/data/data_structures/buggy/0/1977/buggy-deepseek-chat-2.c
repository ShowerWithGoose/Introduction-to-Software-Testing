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
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Error: When i=0, str[i-1] accesses out-of-bounds memory. Also, the condition does not check that the character after '-' is greater than the one before it, as required by the problem.
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ Error: This shift logic is flawed; it may overwrite characters incorrectly and does not properly handle the expansion in-place.
            }
            for (int k = 0; k < backwardLength + 1; k++)
            {
                str[i + k] = str[i - 1] + 1 + k; // @@ Error: When i=0, str[i-1] is out-of-bounds. Also, the expansion should start from str[i-1]+1, but the loop overwrites the '-' and adjacent characters incorrectly.
            }
            str[strLength + backwardLength] = '\0'; // @@ Error: This may write beyond the array bounds if backwardLength is negative or too large.
        }
    }
    printf("%s",str);
    return 0;
}