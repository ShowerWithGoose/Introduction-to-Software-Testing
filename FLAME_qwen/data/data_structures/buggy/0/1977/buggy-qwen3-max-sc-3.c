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
    for (int i = 0; i < strLength - 1; ++i) // @@ [Loop condition may skip processing the last character if it's part of a valid expansion pattern ending at the last index. Also, when i=0, str[i-1] accesses str[-1], causing undefined behavior.]
    {
        if (str[i] == '-' && lowOrUp(str[i - 1], str[i + 1]) == 1) // @@ [Accesses str[i-1] when i=0, leading to out-of-bounds read (undefined behavior). Should ensure i > 0 before checking str[i-1].]
        {
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [If the range is like 'a-c', this gives 0, but actual characters to insert are 'b' only (1 char). The formula should be (str[i+1] - str[i-1] - 1), and number of inserted chars is that value minus 1. Also, negative values possible if condition fails but still enters block due to flawed logic.]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [Writing beyond array bounds if backwardLength > 0 and strLength + backwardLength >= 200. Also, shifting logic assumes space exists, but original array size is fixed.]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [If backwardLength is negative (e.g., due to invalid input slipping through), this loop runs with large positive iterations due to unsigned-like behavior, causing buffer overflow.]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [May write beyond array bounds if strLength + backwardLength >= 200. Also, strLength is not updated for subsequent iterations, causing incorrect shifts in later expansions.]
        }
    }
    printf("%s",str);
    return 0;
}