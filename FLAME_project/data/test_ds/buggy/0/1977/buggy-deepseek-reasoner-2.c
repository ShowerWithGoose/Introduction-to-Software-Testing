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
    for (int i = 0; i < strLength - 1; ++i) // @@ [The loop uses the original strLength which does not update after expansions; therefore later '-' characters (e.g., the one after 'u') are never processed again, missing the second expansion.]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Missing check that str[i+1] > str[i-1]; also, when i=0, str[i-1] is out of bounds.]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [When str[i+1] <= str[i-1], backwardLength becomes negative, causing undefined behavior; the problem requires expansion only when second char is greater.]
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