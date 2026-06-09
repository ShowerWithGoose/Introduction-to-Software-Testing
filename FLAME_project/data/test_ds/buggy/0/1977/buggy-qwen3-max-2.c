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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition stops too early; should allow checking up to i = strLength - 2 to safely access str[i+1], but more critically, the logic inside modifies the string and its length during iteration, causing missed expansions like in "B-F" after processing "a-u".]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Accesses str[i-1] when i=0, leading to out-of-bounds read (undefined behavior). Also, does not check that str[i+1] > str[i-1], violating the requirement that expansion only occurs when the right character is greater.]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [Incorrect calculation: number of characters to insert between str[i-1] and str[i+1] should be (str[i+1] - str[i-1] - 1), so the inserted segment length is (str[i+1] - str[i-1] - 1), but this computes one less. For example, 'B' to 'F' should insert C,D,E (3 chars), but this gives 5-2=3? Wait: 'F'-'B'=4, 4-2=2 → wrong. Should be (str[i+1] - str[i-1] - 1) characters to output between, but here it's used as expansion length incorrectly.]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [This shifts part of the string to make room, but the amount shifted (backwardLength) may be negative if str[i+1] <= str[i-1], though the condition above doesn't ensure str[i+1] > str[i-1]. Also, even if positive, the shifting logic is fragile and overwrites data incorrectly when multiple expansions exist.]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [If backwardLength is negative (e.g., when str[i+1] <= str[i-1]), this loop runs with negative upper bound → undefined behavior. But even when valid, the number of characters written is backwardLength+1 = (str[i+1]-str[i-1]-1), which is correct for the middle part, but note that the original '-' and surrounding are being replaced incorrectly. However, the bigger issue is that the algorithm modifies the string in-place while iterating forward, so later parts (like "B-F") may never be processed because i moves past them after expansion.]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [Updates null terminator, but strLength is not updated for subsequent iterations, so later loop bounds and shifts use stale length, causing incorrect behavior on subsequent '-' symbols (e.g., "B-F" is never processed because the loop index i doesn't revisit the new positions where '-' might have been or where new patterns emerge).]
        }
    }
    printf("%s",str);
    return 0;
}