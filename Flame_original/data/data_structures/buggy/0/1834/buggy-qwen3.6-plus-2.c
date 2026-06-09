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
    while (gets(s) != NULL) // @@ gets is removed in C11 standard, causing compilation error in modern environments; use fgets instead
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-') // @@ s[i-1] causes out-of-bounds access when i=0; logic incorrectly skips printing characters adjacent to '-'
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    printf("%c", s[i - 1]); // @@ Prints s[i-1] again, causing duplicate output since it was already printed in the previous iteration
                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1] - 2); j++) // @@ Variable 'j' shadows function 'j', may cause compilation error/warning; loop logic is flawed
                    {
                        printf("%c", s[i - 1] + j + 1);
                    }
                    printf("%c", s[i + 1]); // @@ Prints s[i+1] again, causing duplicate output
                }
                else
                {
                    printf("%c", s[i - 1]); // @@ Prints s[i-1] again, causing duplicate output
                    printf("-");
                    printf("%c", s[i + 1]); // @@ Prints s[i+1] again, causing duplicate output
                }
            }
        }
    }

    return 0;
}