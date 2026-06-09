#include <stdio.h>
#include <stdlib.h>

typedef struct _treenode
{
    int value;
    struct _treenode *left;
    struct _treenode *right;
} NODE, *NODEPTR;
NODEPTR tree_init(int basevalue)
{
    NODEPTR ret = (NODEPTR)malloc(sizeof(NODE));
    ret->value = basevalue;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}
NODEPTR tree_insert(NODEPTR node, int value)
{
    NODEPTR next = (value >= node->value) ? node->right : node->left;
    if (next)
    {
        return tree_insert(next, value);
    }
    next = tree_init(value);
    if (value >= node->value)
    {
        node->right = next;
    }
    else
    {
        node->left = next;
    }
    return next;
}
void tree_enumleaf(NODEPTR node, int height, FILE* stream)
{
    if (node->left == NULL && node->right == NULL)
    {
        fprintf(stream, "%d %d\n", node->value, height);
        return;
    }
    if (node->left)
    {
        tree_enumleaf(node->left, height + 1, stream);
    }
    if (node->right)
    {
        tree_enumleaf(node->right, height + 1, stream);
    }
}

int main()
{
    int cnt, i, value;
    NODEPTR tree;
    scanf("%d", &cnt);
    if (cnt <= 0)
    {
        return 0;
    }
    scanf("%d", &value);
    tree = tree_init(value);
    for (i = 1; i < cnt; i++)
    {
        scanf("%d", &value);
        tree_insert(tree, value);
    }
    tree_enumleaf(tree, 1, stdout);
    return 0;
}


