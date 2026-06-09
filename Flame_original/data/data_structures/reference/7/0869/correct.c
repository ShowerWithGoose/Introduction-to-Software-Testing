#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>3
typedef struct node
{
    int data;
    int high;
    struct node *left, *right;
} Tree;
Tree *first;
Tree *New(Tree *root, int temp, int len); 
void print(Tree *root);
int main()
{
    Tree *root = NULL;
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &temp);

        int len = 0;
        root = New(root, temp, len);
    }
    print(root);
    return 0;
}

Tree *New(Tree *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
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

void print(Tree *root)
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

