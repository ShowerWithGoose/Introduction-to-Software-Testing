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
        else if (num > (*root)->num) // @@ Logical error: The problem specifies that the right child's value should be greater than or equal to the root. Using 'else if' ignores duplicate values. It should be 'else' to handle the '==' case.
        {
            add(num, &((*root)->right));
        }
    }
}
void read(Node *root, int high) // @@ Missing NULL check for the root pointer. If the tree is empty (n=0), accessing root->left will cause a runtime error. It should start with 'if (root == NULL) return;' similar to the reference program.
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
    for (int i = 0; i < n; i++) // @@ Compilation error in C89/C90 standards: declaring the loop variable 'i' inside the 'for' statement is not allowed. It should be declared before the loop.
    {
        int num;
        scanf("%d", &num);
        add(num, &root);
    }
    int high = 1;
    read(root, high);
    return 0;
}