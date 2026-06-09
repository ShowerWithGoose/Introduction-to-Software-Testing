#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct BStree
{
    int data;
    struct BStree *left;
    struct BStree *right;
} BST, *pBST;
pBST CreateBST(int data)
{
    pBST p = (pBST)malloc(sizeof(BST));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
pBST InsertBST(pBST root, int data)
{
    if (root == NULL)
        return CreateBST(data);
    if (data < root->data)
        root->left = InsertBST(root->left, data);
    else
        root->right = InsertBST(root->right, data);
    return root;
}
void PrintLeaf(pBST root, int deepth)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        printf("%d %d\n", root->data, deepth + 1);
    PrintLeaf(root->left, deepth + 1);
    PrintLeaf(root->right, deepth + 1);
}
int main()
{
    int n, data;
    pBST root = NULL;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &data);
        root = InsertBST(root, data);
    }
    PrintLeaf(root, 0);
    return 0;
}

