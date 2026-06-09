#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} tree;
tree *first;
tree *New(tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = temp;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
    }
    else if (temp < root->data)
        root->left = New(root->left, temp, len);
    else if (temp >= root->data)
        root->right = New(root->right, temp, len);
    return root;
}

void print(tree *root)
{
    if (root)
    {
        if (!(root->left) && !(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->left);
        print(root->right);
    }
}

int main()
{
    tree *root = NULL;
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) //´´½¨Ê÷
    {
        scanf("%d", &temp);

        int len = 0;
        root = New(root, temp, len);
    }
    print(root);
    return 0;
}


