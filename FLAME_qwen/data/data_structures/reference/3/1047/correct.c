#include <stdio.h>
#include <string.h>
char s[105];
int main()
{
    gets(s);
    int e = 0, i, st;
    if (s[0] == '0')
    {
        int flag = 1;
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '.')
                e = i;
            if (s[i] != '0' && s[i] != '.' && flag)
            {
                st = i;
                flag = 0;
            }
        }
        e -= st;
    }
    else
    {
        e = strlen(s) - 1;
        for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '.')
                e = i - 1;
        }
        st = 0;
    }
    int cnt = 0;
    for (i = st; s[i] != '\0'; i++)
    {
        if (s[i] == '.')
            continue;
        if (cnt == 1)
            putchar('.');
        putchar(s[i]);
        cnt++;
    }
    putchar('e');
    printf("%d", e);
    return 0;
}
