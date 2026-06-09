#include <stdio.h>
#include <stdlib.h>

int i, j, k;
typedef struct node
{
    int data;
    int deep;
    struct node *left, *right;
} Tree;
Tree *first;

Tree *New(Tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data = temp;
        root->left = root->right = NULL;
        first = root;
        root->deep = len;
    }
    else if (temp < root->data)
        root->left = New(root->left, temp, len);
    else if (temp >= root->data)
        root->right = New(root->right, temp, len);
    return root;
}

void print(Tree *root)
{
    if (root)
    {
        if (root->left==NULL && root->right==NULL)
        {
            printf("%d %d\n", root->data, root->deep);
        }
        print(root->left);
        print(root->right);
    }
}

int main()
{
    Tree *root = NULL;
    int n, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);

        int len = 0;
        len++;
        if (root == NULL)
        {
            root = (Tree *)malloc(sizeof(Tree));
            root->data = temp;
            root->left = root->right = NULL;
            first = root;
            root->deep = len;
        }
        else if (temp < root->data)
            root->left = New(root->left, temp, len);
        else if (temp >= root->data)
            root->right = New(root->right, temp, len);
    }
    print(root);
    return 0;
}




