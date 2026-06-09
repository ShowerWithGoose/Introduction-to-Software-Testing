#include <stdio.h>
#include <ctype.h>  //字符类型判断
#include <string.h> //字符串处理
#include <stdlib.h> //qsort,rand,bsearch
struct bst
{
    int k;
    struct bst *left;
    struct bst *right;
    struct bst *parent;
};
int h = 1;
typedef struct bst BTorder;
typedef struct bst *BTorderpr;
BTorderpr insertBT(int x, BTorderpr root)
{
    if (root == NULL)
    {
        root = (BTorderpr)malloc(sizeof(BTorder));
        root->k = x;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }
    else if (root->k <= x)
    {
        root->right = insertBT(x, root->right);
        root->right->parent = root;
    }
    else if (root->k > x)
    {
        root->left = insertBT(x, root->left);
        root->left->parent = root;
    }
    return root;
}
int dethBT(BTorderpr p)
{
    if (p->parent == NULL)
    {
        return 1;
    }
    else
    {
        return 1 + dethBT(p->parent);
    }
}
void VISIT(BTorderpr root)
{
    if (root->left == NULL && root->right == NULL)
    {
        h = dethBT(root);
        printf("%d %d\n", root->k, h);
    }
}

void perorder(BTorderpr root)
{
    if (root != NULL)
    {
        VISIT(root);
        perorder(root->left);
        perorder(root->right);
    }
}

int main()
{
    int n, t;
    BTorderpr root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        root = insertBT(t, root);
    }
    perorder(root);
    return 0;
}
