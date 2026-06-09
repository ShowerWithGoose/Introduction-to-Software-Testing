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
} Tree;
Tree *first;

Tree *New(Tree *root, int t, int len);
void output(Tree *root);

int main()
{
    Tree *root = NULL;
    int n, t,i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &t);
        int len = 0;
        root = New(root, t, len);
    }
    output(root);
    return 0;
}

Tree *New(Tree *root, int t, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data = t;
        root->left = root->right = NULL;
        first = root;
        root->high = len;
    }
    else if (t < root->data)
        root->left = New(root->left, t, len);
    else if (t >= root->data)
        root->right = New(root->right, t, len);
    return root;
}

void output(Tree *root)
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



