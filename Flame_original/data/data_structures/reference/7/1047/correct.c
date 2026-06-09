#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    int depth;
    struct node *left;
    struct node *right;
} BTnode;
BTnode *insert(int, int, BTnode *);
void inOrderTraversal(BTnode *);
int main()
{
    BTnode *BST = NULL;
    int n, value;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &value);
        BST = insert(value, 0, BST);
    }
    inOrderTraversal(BST);
    return 0;
}
BTnode *insert(int targ, int dep, BTnode *BST)
{
    dep++;
    if (!BST)
    {
        BST = (BTnode *)malloc(sizeof(BTnode));
        BST->value = targ;
        BST->depth = dep;
        BST->left = BST->right = NULL;
    }
    else if (BST->value > targ)
        BST->left = insert(targ, dep, BST->left);
    else if (BST->value <= targ)
        BST->right = insert(targ, dep, BST->right);
    return BST;
}
void inOrderTraversal(BTnode *BST)
{
    if (BST)
    {
        inOrderTraversal(BST->left);
        if (!BST->left && !BST->right)
            printf("%d %d\n", BST->value, BST->depth);
        inOrderTraversal(BST->right);
    }
}
