#include <stdio.h>
#include <string.h>
char s1[105], s2[105];
int main()
{
    gets(s1);
    int i, j, bit0=0;
    for (i = 0, j = 0; s1[i] != 0; i++)
    {
        if (s1[i] != '.')
        {
            s2[j] = s1[i];
            j++;
        }
    }

    if (s1[0] != '0')
    {
        for (i = 0; s1[i] != '.'; i++)
            ;
        printf("%c.", s2[0]);
        for (j = 1; s2[j] != 0; j++)
        {
            printf("%c", s2[j]);
        }
        printf("e%d", i - 1);
    }
    else
    {
        for (i = 0; s2[i] == '0'; i++)
            bit0 = i;
        if (s2[i + 1] != 0)
        {
            printf("%c.", s2[i]);
        }
        else
        {
            printf("%c", s2[i]);
        }
        for (j = i + 1; s2[j] != 0; j++)
        {
            printf("%c", s2[j]);
        }
        printf("e-%d", bit0 + 1);
    }
    return 0;
}
