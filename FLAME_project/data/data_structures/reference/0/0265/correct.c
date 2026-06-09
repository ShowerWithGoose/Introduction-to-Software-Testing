#include <stdio.h>
#include <string.h>
int isAlphaDigit(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int typeOf(char c)
{
    // 0: other
    // 1: digit
    // 2: upper
    // 3: lower
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 2;
    if (c >= 'a' && c <= 'z')
        return 3;
    return 0;
}

int main()
{
    unsigned int counter = 0;
    char s[1000];
    fgets(s, 1000, stdin);
    int leng = strlen(s);
    for (int i = 0; i < leng; i++)
    {
        char curr = s[i];
        if (i == 0)
        {
            putchar(curr);
            continue;
        }
        char prev = s[i - 1];
        if (curr == '-')
            continue;
        if (prev != '-')
        {
            putchar(curr);
            continue;
        }
        // prev is '-'
        if (i == 1)
        {
            putchar('-');
            putchar(curr);
            continue;
        }
        char ini = s[i - 2];
        if (!isAlphaDigit(curr) && (!isAlphaDigit(ini)))
        {
            putchar('-');
            putchar(curr);
            continue;
        }
        if (curr <= ini || typeOf(curr) != typeOf(ini))
        {
            putchar('-');
            putchar(curr);
            continue;
        }
        for (int j = ini + 1; j <= curr; j++)
        {
            putchar(j);
        }

        /*         if (s[i] != '-' && isAlphaDigit(s[i]) == 0)
                {
                    print(s[i]);
                    continue;
                }
                if (s[i] != '-')
                {

                } */
    }
}
