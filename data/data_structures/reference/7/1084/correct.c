#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long

struct node
{
    int data;
    int h;
    struct node *left, *right;
};

typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p, int item, int m);
void peroder(BTNodeptr p);

int main()
{
    int i, n, m, item;
    BTNodeptr root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        m = 0;
        scanf("%d", &item);
        root = insertBST(root, item, m);
    }
    peroder(root);
    return 0;
}

BTNodeptr insertBST(BTNodeptr p, int item, int m)
{
    m++;
    if (p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
        p->h = m;
    }
    else if (item < p->data)
        p->left = insertBST(p->left, item, m);
    else
        p->right = insertBST(p->right, item, m);
    return p;
}

void peroder(BTNodeptr p)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
        {
            printf("%d %d\n", p->data, p->h);
        }
        peroder(p->left);
        peroder(p->right);
    }
}
