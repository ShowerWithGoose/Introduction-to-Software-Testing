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
        add(num, &root); // @@ [The insertion logic ignores duplicate values (when num == (*root)->num), causing some nodes (like the second 100) to be skipped. According to the problem, right child should be >= root, so duplicates should go to the right.]
    }
    int high = 1;
    read(root, high); // @@ [The traversal order in 'read' is not in-order; it processes left and right subtrees before checking if current node is a leaf, but more critically, the traversal does not guarantee left-to-right leaf output because it's a post-order style. However, the main issue is missing duplicate handling during insertion, which causes the leaf node '100' to be omitted.]
    return 0;
}