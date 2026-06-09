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

typedef struct node
{
    struct node *nxt;
    char s[maxn];
    int cnt;
} NODE, *NODEptr, *LIST;

LIST list, tail;

void init()
{
    list = NULL;
    tail = NULL;
}

LIST isert(LIST list, char str[])
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    memcpy(p->s, str, maxn);
    p->cnt = 1;
    p->nxt = NULL;

    if (list == NULL || strcmp(list->s, str) > 0)
    {
        p->nxt = list;
        list = p;
    }
    else
    {
        NODE *q = list, *r;
        while (q != NULL && strcmp(q->s, str) < 0)
        {
            r = q;
            q = q->nxt;
        }
        p->nxt = q;
        r->nxt = p;
    }
    return list;
}

NODEptr find(char str[])
{
    for (NODE *p = list; p != NULL; p = p->nxt)
    {
        if (strcmp(p->s, str) == 0)
            return p;
    }
    return NULL;
}

char str[maxn];

int getWord()
{
    int ch, cnt = 0;
    memset(str, 0, sizeof(str));
    do
    {
        ch = getchar();
        if (ch == EOF)
            return 0;
    } while (!isalpha(ch));
    do
    {
        ch = tolower(ch);
        str[cnt++] = ch;
        ch = getchar();
        if (ch == EOF)
            return 0;
    } while (isalpha(ch));
    str[cnt] = '\0';
    return 1;
}

int main()
{
    freopen("article.txt", "r", stdin);
    // n = rd(), m = rd(), k = rd();
    init();
    NODE *p;
    while (getWord())
    {
        // printf("%s\n", str);
        p = find(str);
        if (p == NULL)
            list = isert(list, str);
        else
            p->cnt++;
    }
    for (p = list; p != NULL; p = p->nxt)
    {
        printf("%s %d\n", p->s, p->cnt);
    }
}
