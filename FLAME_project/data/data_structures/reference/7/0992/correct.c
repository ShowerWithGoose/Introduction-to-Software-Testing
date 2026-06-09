#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Datatype int

struct node
{
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;

BTNodeptr insertBST(BTNodeptr p, Datatype item)
{
    if (p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
        p->left = insertBST(p->left, item);
    else if (item >= p->data)
        p->right = insertBST(p->right, item);
    // else
    //     do-something; //树中存在该元素
    return p;
}
void inorder(BTNodeptr t, int height)
{
    if (t != NULL)
    {
        if (t->left != NULL || t->right != NULL)
        {
            inorder(t->left, height + 1);
            inorder(t->right, height + 1);
        }
        else
        {
            printf("%d %d\n", t->data, height);
        }
    }
}
void destoryTree(BTNodeptr p)
{
    if (p != NULL)
    {
        destoryTree(p->left);
        destoryTree(p->right);
        free(p);
        p = NULL;
    }
}
int main()
{
    // freopen("data.in", "r", stdin);
    BTNodeptr root = NULL;
    int n = 0, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insertBST(root, x);
    }
    inorder(root, 1);
    destoryTree(root);
}
