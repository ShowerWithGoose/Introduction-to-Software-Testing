#include <stdio.h>
char c[105];
int main()
{
    int i;
    char *p = c;
    gets(c);
    if (c[0] != '0')
    {
        for (i = 0; c[i] != '\0'; i++)
            if (c[i] == '.')
            {
                c[i] = '\0';
                break;
            }
        printf("%c.%s%se%d\n", *p, p + 1, p + i + 1, i - 1);
    }
    else
    {
        for (i = 2; c[i] != '\0'; i++)
            if (c[i] != '0')
                break;
        if (c[i + 1] == '\0')
            printf("%ce-%d", *(p + i), i - 1);
        else
            printf("%c.%se-%d", *(p + i), p + i + 1, i - 1);
    }
    return 0;
}
