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
    while (gets(s) != NULL) // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal of gets from standard library]
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ [Accessing s[i - 1] when i=0 leads to out-of-bounds read (undefined behavior)]
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1) // @@ [When i=0, s[i-1] is invalid; when i is last index, s[i+1] is '\0', leading to invalid comparisons]
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
                    printf("%c", s[i - 1]); // @@ [Same out-of-bounds access when i=0]
                    printf("-");
                    printf("%c", s[i + 1]); // @@ [If i is last character, s[i+1] is '\0', printing null character may not be intended]
                }
            }
        }
    }

    return 0;
}