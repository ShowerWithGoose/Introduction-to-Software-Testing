#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define Min(_A, _B) ((_A) < (_B) ? (_A) : (_B))
#define Max(_A, _B) ((_A) > (_B) ? (_A) : (_B))
#define rd() read()
#define maxn (520)
#define maxm (1005)

typedef struct BSTNODE
{
    int k;
    int dep;
    struct BSTNODE *lsn, *rsn, *p;
} NODE, *NODEptr;

NODEptr root = NULL;

void insertBst(NODEptr z)
{
    NODEptr y, x;
    y = NULL;
    x = root;
    while (x != NULL)
    {
        y = x;
        if (x->k > z->k)
            x = x->lsn;
        else
            x = x->rsn;
    }
    z->p = y;
    if (y == NULL)
    { // dep,p在插入时完成赋值
        z->dep = 1;
        root = z;
    }
    else
    {
        z->dep = y->dep + 1;

        if (y->k > z->k)
            y->lsn = z;
        else
            y->rsn = z;
    }
}

void dfsBst(NODEptr x)
{
    if (x == NULL)
        return;

    dfsBst(x->lsn);
    if (x->lsn == NULL && x->rsn == NULL)
        printf("%d %d\n", x->k, x->dep);
    dfsBst(x->rsn);
}

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

int main()
{
    // freopen("data.in", "r", stdin);
    int n = rd();
    for (int i = 1; i <= n; ++i)
    {
        int x = rd();
        NODEptr p = (NODEptr)malloc(sizeof(NODE));
        p->k = x;
        p->lsn = NULL;
        p->rsn = NULL;
        insertBst(p);
        // dfsBst(root);
        // printf("now is the number:%d\n", x);
    }

    dfsBst(root);
}
