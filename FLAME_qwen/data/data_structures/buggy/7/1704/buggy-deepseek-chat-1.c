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
        else if (num > (*root)->num)
        {
            add(num, &((*root)->right));
        }
        // @@ [Error: When num equals (*root)->num, the node is not inserted, violating the requirement that right child values are greater than or equal to the root. The else-if should be just else to handle the >= case.]
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