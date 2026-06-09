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
    if (root == NULL) return; // @@ [The function does not handle the case where root is NULL, leading to segmentation fault when tree is empty or during recursive calls on NULL children.]
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
    if (root != NULL) read(root, high); // @@ [If the input n is 0, root remains NULL and calling read(root, high) leads to dereferencing NULL pointer. Also, even for n>0, the original read() lacks NULL check at entry.]
    return 0;
}