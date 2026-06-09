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
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [When i=0, str[i-1] is str[-1], which is invalid memory access; also, when i = strLength-2, str[i+1] is valid, but loop should ensure i>0 before checking str[i-1]]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [If expansion range is like 'a-c', this gives 99-97-2=0, but should expand to 'b'; logic for number of chars to insert is off by one]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [This shifts part of the string right to make room, but strLength hasn't been updated yet; also, writing beyond array bounds possible if backwardLength > 0 and total length exceeds 200]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [backwardLength can be negative if str[i+1] <= str[i-1], but condition above ensures str[i+1] > str[i-1]? Actually, lowOrUp doesn't check ordering, so this could be negative]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [Modifying string length mid-loop causes subsequent iterations to process shifted characters incorrectly; also, strLength variable is not updated, leading to inconsistent state]
        }
    }
    printf("%s",str);
    return 0;
}