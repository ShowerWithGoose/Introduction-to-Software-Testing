#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct node
{
    int val;
    struct node *l, *r;
} *head;

struct node* make(int x)
{
    struct node *p = malloc(sizeof(struct node));
    p->val = x, p->l = p->r = NULL;
    return p;
}

void insert(int x)
{
    struct node *p = head;
    while (1)
    {
        if (x < p->val)
        {
            if (p->l == NULL)
            {
                p->l = make(x);
                break;    
            }
            else p = p->l;
        }
        else
        {
            if (p->r == NULL)
            {
                p->r = make(x);
                break;
            }
            else p = p->r;
        }
    }
}

void dfs(struct node *p, int depth)
{
    if (p->l == NULL && p->r == NULL)
    {
        printf("%d %d\n", p->val, depth);
        return ;
    }
    if (p->l != NULL) dfs(p->l, depth + 1);
    if (p->r != NULL) dfs(p->r, depth + 1);
}

int n;
int main()
{
    int tmp;
    scanf("%d", &n);
    if (n > 0)
    {
        scanf("%d", &tmp);
        head = make(tmp);
    }
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d", &tmp);
        insert(tmp);
    }
    dfs(head, 1);
    return 0;
}
