#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
char sh[100000];
int judge(char a, char b);
inline int judge(char a, char b)
{
    if (isdigit(a) && isdigit(b))
        return 1;
    else if (isupper(a) && isupper(b))
        return 1;
    else if (islower(a) && islower(b))
        return 1;
    return 0;
}
int main()
{
    scanf("%s", sh);
    int len = strlen(sh);
    for (int i = 0; i < len; i++)
    {
        if (sh[i] != '-')
            putchar(sh[i]);
        else
        {
            if (judge(sh[i - 1], sh[i + 1]))
                while (++sh[i - 1] < sh[i + 1])
                    putchar(sh[i - 1]);
            else
                putchar(sh[i]);
        }
    }
    return 0;
}
