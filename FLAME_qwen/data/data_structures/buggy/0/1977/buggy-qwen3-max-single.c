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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition may skip valid '-' at second last position; also, accessing str[i-1] when i=0 causes out-of-bounds read]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [When i=0, str[i-1] accesses str[-1], which is undefined behavior]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [If expansion range is just one character (e.g., a-b), backwardLength becomes -1, leading to negative array index in subsequent loops]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [If backwardLength is negative, this writes before the start of the string buffer]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [If backwardLength is -1, loop runs 0 times, skipping necessary insertion; if backwardLength is positive but miscalculated, wrong characters inserted]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [Modifying string length dynamically without ensuring buffer bounds; may overflow str[200]]
        }
    }
    printf("%s",str);
    return 0;
}