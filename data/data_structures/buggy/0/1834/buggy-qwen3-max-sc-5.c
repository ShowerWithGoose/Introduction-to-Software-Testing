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
    while (gets(s) != NULL) // @@ [Use of unsafe and deprecated function 'gets' which may cause compilation error or warning in modern compilers]
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ [Accessing s[i - 1] when i=0 leads to out-of-bounds read (undefined behavior)]
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1) // @@ [Accessing s[i - 1] when i=0 and s[i + 1] when i is last index leads to out-of-bounds read]
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
                    printf("%c", s[i - 1]); // @@ [Accessing s[i - 1] when i=0 is invalid]
                    printf("-");
                    printf("%c", s[i + 1]); // @@ [Accessing s[i + 1] when i is last character (i.e., at '\0') is invalid]
                }
            }
        }
    }

    return 0;
}