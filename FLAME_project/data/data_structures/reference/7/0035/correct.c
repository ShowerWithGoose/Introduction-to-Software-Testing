#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} tree;

void output(tree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        output(root->left);
        output(root->right);
    }
}
tree *first;
tree *New(tree *root, int nums, int len)
{
    len++;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = nums;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
    }
    else if (nums < root->data)
        root->left = New(root->left, nums, len);
    else if (nums >= root->data)
        root->right = New(root->right, nums, len);
    return root;
}

int main()
{
    tree *root = NULL;
    int n, nums;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) //´´½¨Ê÷
    {
        scanf("%d", &nums);

        int len = 0;
        root = New(root, nums, len);
    }
    output(root);
    return 0;
}






