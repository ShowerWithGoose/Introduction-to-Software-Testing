#include <stdio.h>
#include <math.h>
#include <string.h>

char s[100005];

int check(char x, char y)
{
    if (x >= y) return 0;
    if (x >= '0' && x <= '9')
        if (y >= '0' && y <= '9')
            return 1;
    if (x >= 'a' && x <= 'z')
        if (y >= 'a' && y <= 'z')
            return 1;
    if (x >= 'A' && x <= 'Z')
        if (y >= 'A' && y <= 'Z')
            return 1;
    return 0;
}

int main()
{
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i ++ )
    {
        if (s[i] == '-')
        {
            if (!check(s[i - 1], s[i + 1]))
            {
                printf("%c", s[i]);
                continue;
            }
            else
            {
                for (char j = s[i - 1] + 1; j < s[i + 1]; j ++ )
                    printf("%c", j);
            }
        }
        else printf("%c", s[i]);
    }
    return 0;
}
