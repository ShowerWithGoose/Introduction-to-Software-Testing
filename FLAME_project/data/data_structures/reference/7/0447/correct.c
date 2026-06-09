#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct node
{
    int val;
    struct node *left, *right;
    int depth;
} tree, *treep;
void inorderinsert(treep *p, int val, int depth);
int search(treep t, int val);
void visit(treep t);

int main()
{
    int n;
    int val;
    treep root;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        inorderinsert(&root, val, 1);
    }
    visit(root);
    system("pause");
    return 0;
}

void inorderinsert(treep *t, int val, int depth)
{
    if (*t == NULL)
    {
        *t = (treep)malloc(sizeof(treep));
        (*t)->left = NULL, (*t)->right = NULL;
        (*t)->val = val;
        (*t)->depth = depth;
    }
    else if (val < (*t)->val)
        inorderinsert(&((*t)->left), val, depth + 1);
    else
        inorderinsert(&((*t)->right), val, depth + 1);
}

int search(treep t, int val)
{
    if (t == NULL)
        return -1;
    if (val < t->val)
        search(t->left, val);
    else if (val == t->val)
    {
        printf("val=%d,depth=%d", t->val, t->depth);
        return 1;
    }
    else if (val > t->val)
        search(t->right, val);
}

void visit(treep t)
{
    if (t != NULL)
    {
        visit(t->left);
        if (t->left == NULL && t->right == NULL)
            printf("%d %d\n", t->val, t->depth);
        visit(t->right);
    }
}
