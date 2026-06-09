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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition stops too early; should allow checking '-' at position strLength-2, but more critically, the logic inside assumes in-place expansion which shifts indices and breaks subsequent processing]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Accesses str[i-1] when i=0, causing out-of-bounds read; also doesn't check that str[i+1] > str[i-1] as required by problem]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between str[i-1] and str[i+1] is (str[i+1] - str[i-1] - 1), so extra chars needed are (str[i+1] - str[i-1] - 2); but this leads to wrong loop bounds]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [Writing beyond current string length without ensuring buffer capacity; also modifies string while iterating, causing missed or double processing]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [This writes (backwardLength+1) chars starting at i, but should write from str[i-1]+1 up to str[i+1]-1, which is (str[i+1] - str[i-1] - 1) characters]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [Modifies string length mid-loop but loop index i continues linearly, so newly inserted characters may not be checked for further expansions (though not required here), and more importantly, overlapping expansions or multiple '-' may break]
        }
    }
    printf("%s",str);
    return 0;
}