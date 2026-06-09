#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct Tree
{
    int data, count;
    struct Tree *left, *right;
};
typedef struct Tree tree;
typedef struct Tree *treeptr;
treeptr insert(treeptr p, int item, int length);
void perorder(treeptr p);
int max = 1, wait[10000], top = -1;
int main()
{
    int n, item;
    treeptr root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insert(root, item, 1);
    }
    perorder(root);
    return 0;
}
treeptr insert(treeptr p, int item, int length)
{
    if (p == NULL)
    {
        p = (treeptr)malloc(sizeof(treeptr));
        p->data = item;
        p->count = length;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
    {
        p->left = insert(p->left, item, length + 1);
    }
    else if (item >= p->data)
    {
        p->right = insert(p->right, item, length + 1);
    }
    return p;
}
void perorder(treeptr p)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
        {
            printf("%d %d\n", p->data, p->count);
        }
        perorder(p->left);
        perorder(p->right);
    }
}
