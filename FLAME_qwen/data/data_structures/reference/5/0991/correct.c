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

typedef struct data
{
    int a, r;
} DATA;

DATA a[maxn], b[maxn];
int na, nb;

void getData(DATA a[], int *n)
{
    char ch;
    while (1)
    {
        scanf("%d %d", &a[(*n)].a, &a[(*n)].r);
        ch = getchar();
        (*n)++;
        if (ch == '\n' || ch == EOF)
            break;
    }
}

typedef struct node
{
    DATA d;
    struct node *nxt;
} NODE, *LIST, *NODEptr;

LIST list, tail;

void init()
{
    list = NULL;
    tail = NULL;
}

LIST isert(LIST list, DATA *tmp)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->d = *tmp;
    p->nxt = NULL;

    if (list == NULL || tmp->r > list->d.r)
    {
        p->nxt = list;
        list = p;
    }
    else
    {
        NODE *r, *q = list;
        while (q != NULL && q->d.r >= tmp->r)
        {
            r = q;
            q = q->nxt;
        }
        p->nxt = q;
        r->nxt = p;
    }
    return list;
}

LIST find(int val)
{
    for (NODE *p = list; p != NULL; p = p->nxt)
        if (p->d.r == val)
            return p;
    return NULL;
}

int main()
{
    // freopen("data.in", "r", stdin);
    // FILE *in, *out;
    // out = fopen("ordered.txt", "w");
    // in = fopen("books.txt", "r");
    getData(a, &na);
    getData(b, &nb);
    // for (int i = 0; i < na; ++i)
    //     printf("%d %d\n", a[i].a, a[i].r);
    // for (int i = 0; i < nb; ++i)
    //     printf("%d %d\n", b[i].a, b[i].r);
    int ta, tr;
    NODE *p;
    DATA tmp;
    for (int i = 0; i < na; ++i)
    {
        for (int j = 0; j < nb; ++j)
        {
            ta = a[i].a * b[j].a;
            tr = a[i].r + b[j].r;
            p = find(tr);
            if (p != NULL)
                p->d.a += ta;
            else
            {
                tmp.a = ta;
                tmp.r = tr;
                list = isert(list, &tmp);
            }
        }
    }
    for (NODE *p = list; p != NULL; p = p->nxt)
    {
        printf("%d %d ", p->d.a, p->d.r);
    }
}
