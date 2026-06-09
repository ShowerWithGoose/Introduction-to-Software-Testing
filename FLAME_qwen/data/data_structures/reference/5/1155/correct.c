#include <stdio.h>
#include <stdlib.h>

typedef long long ElemType;
typedef struct Node
{
    ElemType num;
    ElemType index;
    struct Node *link;
}Node;
typedef struct Node *linkptr;

linkptr insert(linkptr L, ElemType a, ElemType b)
{
    linkptr p, r = L, t = L;
    p = (linkptr)malloc(sizeof(Node));
    p->num = a;
    p->index = b;
    p->link = NULL;
    if (L == NULL)
        L = p;
    else
    {
        while (t->index > b)
        {
            r = t;
            t = t->link;
            if (t == NULL)
                break;
        }
        if (t)
        {
            p->link = r->link;
            r->link = p;
        }
        else
        {
            r->link = p;
        }
    }
    return L;
}

linkptr add(linkptr L, long long position, ElemType a, ElemType b)
{
    linkptr q = L;
    while (position - 1 > 0)
    {
        q = q->link;
        position--;
    }
    q->num += a;
    return L;
}

long long search(linkptr L, ElemType b)
{
    linkptr p = L;
    long long count = 1;
    if (L == NULL)
        return -1;
    while (p->index != b)
    {
        p = p->link;
        count++;
        if (p == NULL)
            break;
    }
    if (p)
        return count;
    else
        return -1;
}

int main()
{
    linkptr ans = NULL, L = NULL, p = NULL;
    ElemType a, b, m = 20000000000, po;
    while (scanf("%lld%lld", &a, &b) != EOF)
    {
        if (m <= b)
        {
            for (p = L; p; p = p->link)
            {
                po = search(ans, p->index + b);
                if (po != -1)
                    ans = add(ans, po, p->num * a, p->index + b);
                else
                    ans = insert(ans, p->num * a, p->index + b);
            }
            break;
        }
        L = insert(L, a, b);
        m = b;
    }
    while (scanf("%lld%lld", &a, &b) != EOF)
    {
        for (p = L; p; p = p->link)
            {
                po = search(ans, p->index + b);
                if (po != -1)
                    ans = add(ans, po, p->num * a, p->index + b);
                else
                    ans = insert(ans, p->num * a, p->index + b);
            }
    }
    for (p = ans; p; p = p->link)
    {
        if (p->num != 0)
        {
            printf("%lld %lld ", p->num, p->index);
        }
    }
    return 0;
}

