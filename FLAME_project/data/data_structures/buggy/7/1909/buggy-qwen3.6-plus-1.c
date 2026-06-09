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
    node *tem = (node *)malloc(sizeof(node *)); // @@ [Error: malloc allocates size of pointer instead of size of struct. Should be sizeof(node). This causes memory corruption and Runtime Error.]
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
    if (root == NULL) return; // @@ [Error: Missing NULL check for root. If a node has only one child, the other child is NULL. Calling LeftLowPrint on NULL causes Segmentation Fault (Runtime Error).]
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d %d\n", root->data,CurrentHight);
        return;
    }
    else
    {
        LeftLowPrint(root->left,CurrentHight+1);
        LeftLowPrint(root->right,CurrentHight+1);
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