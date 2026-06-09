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
    node *tem = (node *)malloc(sizeof(node *)); // @@ [Error: malloc(sizeof(node *)) allocates memory for a pointer, not for the struct. Should be malloc(sizeof(node))]
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
        LeftLowPrint(root->left,CurrentHight+1); // @@ [Error: When root->left is NULL, this will cause a segmentation fault by dereferencing a NULL pointer. Should check for NULL before recursing.]
        LeftLowPrint(root->right,CurrentHight+1); // @@ [Error: Same issue as above; when root->right is NULL, this will cause a segmentation fault.]
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