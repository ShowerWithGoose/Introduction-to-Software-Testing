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
    for (int i = 0; i < strLength - 1; ++i) // @@ The loop condition and logic are flawed. It iterates based on the original length but modifies the string in-place, shifting indices. Also, it doesn't check if the character after '-' is strictly greater than the one before, only if they are the same type. More critically, when an expansion happens, the string length changes, but `strLength` is not updated, and subsequent iterations use stale indices. For input "a-uB-F", after expanding "a-u", the string becomes "abcdefghijklmnopqrstuB-F". The loop continues with old indices. The second part "B-F" is at a new position. The loop `i` goes up to original `strLength - 1`. The logic for shifting and updating is complex and error-prone in a single pass without updating length or index correctly. Specifically, after expanding `a-u`, the `B-F` part shifts. The loop variable `i` continues incrementing, potentially skipping the new `-` in `B-F` or processing it incorrectly because the bounds `strLength - 1` are from the original string. Additionally, the condition `lowOrUp` returns 1 for same type, but the problem requires the second char to be *greater* than the first. This check is missing.
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ Missing check: str[i+1] > str[i-1]. If str[i+1] <= str[i-1], no expansion should occur.
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2;
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j];
            }
            for (int k = 0; k < backwardLength + 1; k++)
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0';
        }
    }
    printf("%s",str);
    return 0;
}