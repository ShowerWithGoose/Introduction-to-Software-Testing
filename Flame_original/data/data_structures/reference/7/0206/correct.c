#include <stdio.h>
#include <stdlib.h>
struct bst
{
    int val;
    struct bst *left, *right;
};
typedef struct bst bst;
typedef struct bst *pbst;
pbst create(pbst root, int val)
{
    if (root == NULL)
    {
        root = (pbst)malloc(sizeof(bst));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (val < root->val)
        root->left = create(root->left, val);
    else
        root->right = create(root->right, val);
    return root;
}
void print(pbst root, int height)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
    {
        print(root->left, height + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d %d\n", root->val, height);
        return;
    }
    if (root->right != NULL)
    {
        print(root->right, height + 1);
    }
}
int main()
{
    pbst root = NULL;
    int n, val;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &val);
        root = create(root, val);
    }
    print(root, 1);
}
