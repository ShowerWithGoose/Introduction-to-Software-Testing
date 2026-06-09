#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *left;
    int num;
    struct node *right;
} Node;

void add(int num, Node **root)
{
    if (*root == NULL)
    {
        *root = (Node *)malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->num = num;
        (*root)->right = NULL;
    }
    else
    {
        if (num < (*root)->num)
        {
            add(num, &((*root)->left));
        }
        else if (num > (*root)->num) // @@ This condition ignores equal values; should be `else` to insert equal values into the right subtree as required.
        {
            add(num, &((*root)->right));
        }
    }
}
void read(Node *root, int high)
{
    if (root->left != NULL)
    {
        read(root->left, high + 1);
    }
    if (root->right != NULL)
    {
        read(root->right, high + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d %d\n", root->num, high);
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        add(num, &root);
    }
    int high = 1;
    read(root, high);
    return 0;
}