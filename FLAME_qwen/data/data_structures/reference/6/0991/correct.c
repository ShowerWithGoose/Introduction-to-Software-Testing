#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define Min(_A, _B) ((_A) < (_B) ? (_A) : (_B))
#define Max(_A, _B) ((_A) > (_B) ? (_A) : (_B))
#define rd() read()
#define maxn (105)
#define maxm (2005)
#define st 32
#define ed 126

int read()
{
    register int x = 0, f = 0;
    register char ch;
    do
    {
        ch = getchar();
        f |= (ch == '-');
    } while (ch < '0' || ch > '9');
    do
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return f ? (-x) : x;
}

int stk[maxn], top, mx = 99;

void init()
{
    top = -1;
}

int main()
{
    // freopen("data.in", "r", stdin);
    // n = rd(), m = rd(), k = rd();
    init();
    int op, x;
    while (scanf("%d", &op) == 1)
    {
        if (op == 1)
        {
            x = rd();
            if (top == mx)
            {
                printf("error ");
            }
            else
            {
                stk[++top] = x;
            }
        }
        else if (op == 0)
        {
            if (top == -1)
                printf("error ");
            else
            {
                printf("%d ", stk[top--]);
            }
        }
        else if (op == -1)
        {
            return 0;
        }
    }
}
