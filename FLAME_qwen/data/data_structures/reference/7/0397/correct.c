#include <stdio.h>
#include <stdlib.h>
typedef struct _bst
{
    int data;
    struct _bst *left;
    struct _bst *right;
} TreeNode;

TreeNode *CreateNode(int d)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    return new;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/
void Print(TreeNode *node, int depth)
{
    if (node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            printf("%d %d\n", node->data, depth);
        }
        else
        {
            Print(node->left, depth + 1);
            Print(node->right, depth + 1);
        }
    }
    return;
}

int main()
{
    int _n, data;
    //栽树
    scanf("%d", &_n);
    scanf("%d", &data);
    TreeNode *root = CreateNode(data);
    for (int i = 1; i < _n; i++)
    {
        scanf("%d", &data);
        TreeNode *node = CreateNode(data);
        TreeNode *p = root;
        while (1)
        {
            if (p->data > data)
            {
                if (p->left == NULL)
                {
                    p->left = node;
                    break;
                }
                else
                {
                    p = p->left;
                }
            }
            else
            {
                if (p->right == NULL)
                {
                    p->right = node;
                    break;
                }
                else
                {
                    p = p->right;
                }
            }
        }
    }

    //遍历
    Print(root, 1);
    //system("pause");
    return 0;
}
