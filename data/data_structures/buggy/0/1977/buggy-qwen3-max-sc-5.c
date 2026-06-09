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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition may skip last character, but more critically, when i=0 and str[0]=='-', accessing str[i-1] leads to out-of-bounds read]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [When i=0, str[i-1] accesses str[-1], which is undefined behavior]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [If expansion range is small (e.g., a-b), backwardLength becomes negative, leading to incorrect memory shifts]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [If backwardLength is negative, this writes before the start of the string buffer, causing buffer underflow]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [If backwardLength is negative, loop runs with negative upper bound, which in C means very large positive due to unsigned comparison, causing buffer overflow]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [If backwardLength is negative, this may place '\0' before current string end, truncating valid data or writing out of bounds]
        }
    }
    printf("%s",str);
    return 0;
}