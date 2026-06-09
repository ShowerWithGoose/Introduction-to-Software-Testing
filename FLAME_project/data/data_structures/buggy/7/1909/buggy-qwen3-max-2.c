#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data, depth;
    struct tree *left;
    struct tree *right;
    struct tree *up;

} node;
node *root = NULL;
node *getnewnode(int data)
{
    node *tem = (node *)malloc(sizeof(node *)); // @@ [Incorrect memory allocation: should be sizeof(node), not sizeof(node *). This leads to undefined behavior and likely a runtime error due to insufficient memory allocated for the struct.]
    tem->data = data;
    tem->left = NULL;
    tem->right = NULL;
    return tem;
}
node *Insert(node *root, int data)
{
    if (root == NULL)
    {
        root = getnewnode(data);
        return root;
    }
    else
    {
        if (data < root->data)
        {
            root->left = Insert(root->left, data);
        }
        else
        {
            root->right = Insert(root->right, data);
        }
    }
    return root;
}
void LeftLowPrint(node *root,int CurrentHight)
{
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d %d\n", root->data,CurrentHight);
        return;
    }
    else
    {
        LeftLowPrint(root->left,CurrentHight+1); // @@ [Potential null pointer dereference: if root->left is NULL, calling LeftLowPrint on it will crash. The function assumes non-NULL children when recursing, but doesn't check before recursive calls.]
        LeftLowPrint(root->right,CurrentHight+1); // @@ [Same issue as above: if root->right is NULL, this call will cause a segmentation fault.]
    }
}
int main()
{
    int n, a;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        root = Insert(root, a);
    }
    LeftLowPrint(root,1);
}