#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} BTNode;
BTNode *insertBST(BTNode *p, int item);
void perorder(BTNode *t,int h);
void visit(BTNode *t,int h);
int h = 1;
int main()
{
    int n;
    BTNode *root = NULL;
    scanf("%d", &n);
    int *num = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < n; i++)
        root = insertBST(root, num[i]);

    perorder(root,h);

    free(num);
    return 0;
}
BTNode *insertBST(BTNode *p, int item) /*递归算法*/
{

    if (p == NULL)
    {
        p = (BTNode *)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
    {
        p->left = insertBST(p->left, item);
    }
    else if (item > p->data) // @@ The problem states that right child is greater than or equal to the root. This condition excludes equal items, causing them to be ignored instead of inserted into the right subtree. It should be item >= p->data.
    {
        p->right = insertBST(p->right, item);
    }
    return p;
}
void perorder(BTNode *t,int h)
{
    if (t != NULL)
    {

        visit(t,h);
        perorder(t->left,h+1);
        perorder(t->right,h+1);
    }
}
void visit(BTNode *t,int h)
{
    if (t->left == NULL && t->right == NULL)
    {
        printf("%d %d\n", t->data, h);
    }
}