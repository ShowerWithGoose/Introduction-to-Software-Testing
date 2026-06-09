#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define maxn (1005)
#define maxm (2005)

typedef long long ll;

char getC()
{
    char ch;
    do
    {
        ch = getchar();
    } while (ch == ' ');
    return ch;
}

int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("output.a", "w", stdout);
    char ch;
    ll tmp = 1, val = 0, ans = 0;
    int flag = 1;
    while (1)
    {
        ch = getC();
        if (ch >= '0' && ch <= '9')
        {

            val = 0;
            while (isdigit(ch))
            {
                val = val * 10 + ch - '0';
                ch = getC();
            }
            if (flag)
                tmp *= val;
            else
                tmp /= val;
        }

        if (ch == '*')
        {
            flag = 1;
            continue;
        }
        else if (ch == '/')
        {
            flag = 0;
            continue;
        }

        ans += tmp;

        if (ch == '=')
            break;

        tmp = (ch == '+') ? 1 : -1;
        flag = 1;

        // printf("%lld\n", ans);
    }
    printf("%lld", ans);
}
