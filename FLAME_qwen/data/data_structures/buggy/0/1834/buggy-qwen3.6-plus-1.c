#include <stdio.h>
#include <string.h>
int j(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[10000];
    while (gets(s) != NULL) // @@ The gets() function is deprecated and removed in the C11 standard, which causes a compilation error on modern compilers. Use fgets() instead.
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ Accessing s[i-1] when i=0 results in out-of-bounds memory access, leading to undefined behavior or a runtime crash.
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1) // @@ Accessing s[i-1] when i=0 results in out-of-bounds memory access. The code does not handle the case where '-' appears at the beginning of the string.
                {
                    printf("%c", s[i - 1]);
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++)
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]);
                }
                else
                {
                    printf("%c", s[i - 1]);
                    printf("-");
                    printf("%c", s[i + 1]);
                }
            }
        }
    }

    return 0;
}