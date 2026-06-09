#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int high;
    struct node *lchild, *rchild;
}BTNode, *BTREE;
BTREE BUILDBT(BTREE root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (BTREE)malloc(sizeof(BTNode));
        root->data = temp;
        root->lchild = root->rchild = NULL;
        root->high = len;
    }
    else if (temp < root->data)
        root->lchild = BUILDBT(root->lchild, temp, len);
    else if (temp >= root->data)
        root->rchild = BUILDBT(root->rchild, temp, len);
        return root;
}
void print(BTREE root)
{
    if (root)
    {
        if (!(root->lchild) && !(root->rchild))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->lchild);
        print(root->rchild);
    }
}
int main()
{
    BTREE root = NULL;
    int i, n, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++) //´´½¨Ê÷
    {
        scanf("%d", &temp);
        root = BUILDBT(root, temp, 0);
    }
    print(root);
    return 0;
}

