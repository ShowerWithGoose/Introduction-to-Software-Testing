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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition stops too early; should allow checking up to i = strLength - 2 to safely access str[i+1], but more critically, the expansion logic modifies the string in-place while iterating, which causes missed expansions like in "B-F" after processing "a-u".]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Does not check if str[i-1] and str[i+1] are valid indices (i.e., i > 0). For i=0, str[-1] is accessed, causing undefined behavior. Also, does not verify that str[i+1] > str[i-1], violating the requirement that expansion only occurs when the right character is greater.]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between str[i-1] and str[i+1] should be (str[i+1] - str[i-1] - 1), so the inserted segment length is (str[i+1] - str[i-1] - 1), but this computes one less. For example, from 'B' to 'F', difference is 4, so 3 chars (C,D,E) should be inserted, but this gives 4 - 2 = 2, leading to wrong expansion.]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [Shifting logic is flawed: it shifts from the end but doesn't account for cumulative length changes during multiple expansions. Also, strLength is not updated after modification, so subsequent iterations use outdated length.]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [Due to incorrect backwardLength, this loop writes wrong number of characters. For 'B'-'F', it should write C,D,E,F? But actually should write C,D,E (since F is already present). However, the original '-' and surrounding chars are being replaced incorrectly. The correct approach is to output from str[i-1]+1 to str[i+1]-1, then keep str[i+1]. This code overwrites the '-' and part of the following, but fails to preserve the trailing character properly.]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [strLength is never updated, so this null-termination is at a fixed offset, but the string has been modified in place with shifting. Moreover, multiple expansions will compound errors because strLength remains original value.]
        }
    }
    printf("%s",str);
    return 0;
}