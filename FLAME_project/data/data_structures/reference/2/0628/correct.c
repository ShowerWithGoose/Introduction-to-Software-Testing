#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int len, lo, ln, n[200];
char s[200], o[200];

int getN(int *pi)
{
    int num = 0;
    while (isdigit(s[*pi]))
    {
        num = num * 10 + s[*pi] - '0';
        (*pi)++;
    }
    return num;
}

int cal(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
    return 0;
}

int main()
{
    char str[200] = "";
    gets(str);
    for (int i = 0; str[i] != '='; ++i)
    {
        if (str[i] != ' ')
            s[len++] = str[i];
    }
    s[len] = '\0';
    for (int i = 0; i < len;)
    {
        if (isdigit(s[i]))
        {
            n[++ln] = getN(&i);
            if (o[lo] == '*' || o[lo] == '/')
            {
                n[ln - 1] = cal(n[ln - 1], n[ln], o[lo]);
                --lo, --ln;
            }
        }
        else
            o[++lo] = s[i], ++i;
    }
    for (int i = 1, j = lo; i < j; ++i, --j)
    {
        o[i] += o[j];
        o[j] = o[i] - o[j];
        o[i] -= o[j];
    }
    for (int i = 1, j = ln; i < j; ++i, --j)
    {
        n[i] += n[j];
        n[j] = n[i] - n[j];
        n[i] -= n[j];
    }
    while (lo)
    {
        n[ln - 1] = cal(n[ln], n[ln - 1], o[lo]);
        --lo, --ln;
    }
    printf("%d\n", n[ln]);
    return 0;
}
