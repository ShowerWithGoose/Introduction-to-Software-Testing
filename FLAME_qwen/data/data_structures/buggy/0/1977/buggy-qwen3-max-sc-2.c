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
            int backwardLength = str[i + 1] - str[i - 1] - 2; // @@ [If str[i+1] - str[i-1] is 1 (e.g., 'a' and 'b'), backwardLength becomes -1, leading to negative array indexing or incorrect shifting.]
            int backNum = strLength - i - 1;
            for (int j = 0; j < backNum; j++)
            {
                str[strLength - 1 - j + backwardLength] = str[strLength - 1 - j]; // @@ [If backwardLength is negative, this writes to memory before the string start, causing buffer underflow/undefined behavior.]
            }
            for (int k = 0; k < backwardLength + 1; k++) // @@ [If backwardLength is negative, loop condition fails immediately, skipping expansion even when needed (e.g., a-b should expand to 'ab'). Also, logic assumes expansion replaces '-', but doesn't account for correct overwrite range.]
            {
                str[i + k] = str[i - 1] + 1 + k;
            }
            str[strLength + backwardLength] = '\0'; // @@ [Modifies string length dynamically but doesn't update strLength for subsequent iterations, causing later expansions to use outdated length and potentially corrupt memory.]
        }
    }
    printf("%s",str);
    return 0;
}