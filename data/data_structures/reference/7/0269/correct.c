#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}
void printBst(struct node *root, int height)
{
    if (root != NULL)
    {
        if (root->left != NULL)
            printBst(root->left, height + 1);
        if (root->left == NULL && root->right == NULL)
        {
            printf("%d %d\n", root->data, height);
            return;
        }
        if (root->right != NULL)
            printBst(root->right, height + 1);
    }
    else
        return;
}
int main()
{
    int i, n, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printBst(root, 1);
    return 0;
}

