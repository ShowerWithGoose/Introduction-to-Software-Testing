#include <stdio.h>
#include <stdlib.h>

typedef struct _Func
{
    long long exp, val;
} Func;

int cmp(const void* x, const void* y)
{
    return ((Func*)y)->exp - ((Func*)x)->exp;
}

#define N 100005
Func a[N], b[N], ans[N];
int cnt_a, cnt_b;

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    long long e, v;
    while(~scanf("%lld%lld", &v, &e))
    {
        a[cnt_a].exp = e;
        a[cnt_a].val = v;
        cnt_a++;
        if(getchar() == '\n') break;
    }
    while(~scanf("%lld%lld", &v, &e))
    {
        b[cnt_b].exp = e;
        b[cnt_b].val = v;
        cnt_b++;
        if(getchar() == '\n') break;
    }
    for(int i = 0; i < cnt_a; i++)
        for(int j = 0; j < cnt_b; j++)
        {
            ans[i * cnt_b + j].exp = a[i].exp + b[j].exp;
            ans[i * cnt_b + j].val = a[i].val * b[j].val;
        }
    qsort(ans, cnt_a * cnt_b, sizeof(Func), cmp);
    e = -1; v = 0;
    for(int i = 0; i < cnt_a * cnt_b; i++)
    {
        if(e == ans[i].exp)
        {
            v += ans[i].val;
        }
        else
        {
            if(~e) printf("%lld %lld ", v, e);
            e = ans[i].exp;
            v = ans[i].val;
        }
    }
    if(~e) printf("%lld %lld\n", v, e);
    return 0;
}
