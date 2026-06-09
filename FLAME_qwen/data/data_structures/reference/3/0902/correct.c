#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[1000];
int main()
{
    fgets(str, 1000, stdin);
    int pt;
    int len = strlen(str) - 1;
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            pt = i;
        }
    }
    if (str[0] == '0')
    {
        for (int i = 2; i < len; i++)
        {
            if (str[i] != '0')
            {
                printf("%c", str[i]);
                if (i != len - 1)
                    printf(".");
                for (int j = i + 1; j < len; j++)
                {
                    printf("%c", str[j]);
                }
                printf("e%d", pt - i);
                return 0;
            }
        }
    }
    printf("%c.", str[0]);
    for (int i = 1; i < len; i++)
    {
        if (str[i] == '.')
            continue;
        printf("%c", str[i]);
    }
    printf("e%d", pt - 1);
    return 0;
}
