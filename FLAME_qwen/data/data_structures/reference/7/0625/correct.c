#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst
{
    int dat;
    struct bst *left, *right;
} * Bst;

int layer = 1;

Bst Insert(Bst node, int tmp);
void order(Bst node);

int main()
{
    Bst root = NULL;
    int x;
    int number;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &number);
        root = Insert(root, number);
    }
    order(root);
    return 0;
}

Bst Insert(Bst node, int tmp)
{
    if (node == NULL)
    {
        node = (Bst)malloc(sizeof(struct bst));
        node->dat = tmp;
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        if (tmp >= node->dat)
            node->right = Insert(node->right, tmp);
        else
            node->left = Insert(node->left, tmp);
    }
    return node;
}

void order(Bst node)
{
    if (node != NULL)
    {
        if (node->left == NULL && node->right == NULL)
        {
            printf("%d %d\n", node->dat, layer);
        }
        layer++;
        order(node->left);
        order(node->right);
        layer--;
    }
}


