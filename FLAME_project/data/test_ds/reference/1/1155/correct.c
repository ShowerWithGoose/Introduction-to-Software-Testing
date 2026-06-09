#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[10000];
int i, j, k;

int main()
{
    gets(s);
    for (i = 0; i < strlen(s); i ++)
    {
        if (s[i] != '-')
            printf("%c", s[i]);
        else
        {
            if (s[i - 1] <= '9' && s[i - 1] >= '0' && s[i + 1] <= '9' && s[i + 1] >= '0' && s[i + 1] > s[i - 1] || s[i - 1] <= 'z' && s[i - 1] >= 'a' && s[i + 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] > s[i - 1] || s[i - 1] <= 'Z' && s[i - 1] >= 'A' && s[i + 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] > s[i - 1])
            {
                j = s[i + 1] - s[i - 1];
                for (k = 1; k <= j - 1; k ++)
                    printf("%c", s[i - 1] + k);
            }
            else
                printf("%c", s[i]);
        }
    }
    return 0;
}
