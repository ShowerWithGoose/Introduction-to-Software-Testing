#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn (1005)
#define maxm (2005)

char s[maxn];
char s2[maxm];
char std[3][2] = {{'0', '9'}, {'A', 'Z'}, {'a', 'z'}};

int cck(char *p) //检查是否满足交换性质
{
    if (*p == '\0')
        return 0;

    for (int i = 0; i < 3; ++i)
        if (*(p - 1) >= std[i][0] && *(p + 1) <= std[i][1] && *(p + 1) > *(p - 1))
            return 1;
    return 0;
}

char *fillBlank(char *p1, char *p2) //在s2中填满字符并且返回尾指针
{
    for (char val = *(p1 - 1); val <= *(p1 + 1); ++val)
    {
        *p2 = val;
        p2++;
    }
    return p2;
}

int main()
{
    scanf("%s", s);

    for (char *p1 = s, *p2 = s2; *p1 != '\0'; ++p1)
    {

        if ((*p1) == '-' && cck(p1))
            p2 = fillBlank(p1++, --p2);
        else
        {
            *p2 = *p1;
            ++p2;
        }
    }
    puts(s2);
    // freopen("data.in", "r", stdin);
    // freopen("output.a", "w", stdout);
}
