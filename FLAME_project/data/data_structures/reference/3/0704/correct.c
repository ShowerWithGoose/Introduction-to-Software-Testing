#include <stdio.h>
char s[1000];
int cnt0_begin, cnt0_end;
char str[1000];
char *xiao;
char *zheng;
int main()
{
    gets(s);
    int len, point;
    len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '.')
        {
            point = i;
            break;
        }
    }
    int end;
    for (end = len - 1; s[end] == '0'; end--)
        ;
    s[end + 1] = '\0';
    if (s[0] == '0')
    {
        int j;
        for (j = point + 1; s[j] == '0'; j++)
        {
            cnt0_begin++;
        }
        // str[0] = s[j];
        if (s[j + 1] == '\0')
        {
            // str[1] = 'e';
            // str[2] = '-';
            // str[3] = '\0';
            printf("%ce-%d", s[j], cnt0_begin + 1);
        }
        else
        {
            xiao = &s[j + 1];
            // str[1] = '.';
            printf("%c.%se-%d", s[j], xiao, cnt0_begin + 1);
        }
    }
    else
    {
        s[point] = '\0';
        zheng = &s[1];
        xiao = &s[point + 1];
        printf("%c.%s%se%d", s[0], zheng, xiao, point - 1);
    }
}
