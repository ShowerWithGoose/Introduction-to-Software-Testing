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
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ Missing check that i > 0 and that str[i-1] < str[i+1]; also potential access of str[-1] when i==0
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ Incorrect formula; should be (str[i+1] - str[i-1] - 1) to get number of characters to insert
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ Shift distance is off; should shift the suffix (including the right character) by (backwardLength - 1) positions, not backwardLength
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ Loop bound should be k < backwardLength (i.e., backwardLength iterations), because backwardLength is the number of characters to insert
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ Null terminator placed at wrong index; after correction, should be strLength + backwardLength - 1; also strLength is not updated, causing subsequent loop iterations to use incorrect length
        }
    }
    printf("%s",str);
    return 0;
}