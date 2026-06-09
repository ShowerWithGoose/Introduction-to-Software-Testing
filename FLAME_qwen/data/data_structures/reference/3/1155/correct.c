#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200];
int zero, i, j;

int main()
{
    gets(s);
    if (s[0] == '0')
    {
        i = 2;
        zero = 1;
        while (s[i] == '0')
        {
            zero ++;
            i ++;
        }
        if (s[i + 1] != '\0')
        {
            printf("%c.", s[i]);
            for (j = i + 1; j < strlen(s); j ++)
                printf("%c", s[j]);
        }
        else
            printf("%c", s[i]);
        printf("e-%d", zero);
    }
    else
    {
        i = 1;
        while (s[i] != '.')
        {
            zero ++;
            i ++;
        }
        printf("%c.", s[0]);
        for (j = 1; j < strlen(s); j ++)
            if (s[j] != '.')
                printf("%c", s[j]);
        printf("e%d", zero);
    }
    return 0;
}
