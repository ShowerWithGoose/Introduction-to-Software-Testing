#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    long long a;
    long long x;
    struct node *next;
};
typedef struct node *ptr;
ptr insertNode(ptr head, long long a, long long x)
{
    ptr p = head, q = NULL, r = NULL;
    r = (ptr)malloc(sizeof(struct node));
    r->a = a;
    r->x = x;
    r->next = NULL;
    if (head == NULL)
        return r;
    for (p = head; p != NULL && p->x > x;)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL && p->x == x)
    {
        p->a += a;
    }
    else if (p == head)
    {
        r->next = p;
        return r;
    }
    else
    {
        q->next = r;
        r->next = p;
    }
    return head;
}
int printNode(ptr head)
{
    if (head == NULL)
        return 0;
    ptr p;
    for (p = head; p != NULL; p = p->next)
    {
        if (p->a != 0)
        {
            printf("%lld ", p->a);
            printf("%lld ", p->x);
        }
    }
    return 0;
}
int main()
{
    ptr line = NULL, ans = NULL;
    long long a, x, tmp = 2147483647;
    while ((scanf("%lld%lld", &a, &x)) != EOF)
    {
        if (tmp <= x)
        {
            ptr p = NULL;
            for (p = line; p != NULL; p = p->next)
            {
                ans = insertNode(ans, (p->a) * a, (p->x) + x);
            }
            break;
        }
        line = insertNode(line, a, x);
        tmp = x;
    }
    tmp = 2147483647;
    while ((scanf("%lld%lld", &a, &x)) != EOF)
    {
        ptr q = NULL;
        for (q = line; q != NULL; q = q->next)
        {
            ans = insertNode(ans, a * q->a, x + q->x);
        }
    }
    printNode(ans);
    return 0;
}
