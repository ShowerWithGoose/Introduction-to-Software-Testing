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

Tree *toNew(Tree *root, int temp, int len);
void printNode(Tree *root);
int main()
{
    Tree *root= NULL;
    int n, temp;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &temp);
        int len = 0;
        root = toNew(root, temp, len);
    }
    printNode(root);
    return 0;
}
Tree *toNew(Tree *root, int temp, int len)
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
        root->left = toNew(root->left, temp, len);
    else if (temp >= root->data)
        root->right = toNew(root->right, temp, len);
    return root;
}
void printNode(Tree *root)
{
    if (root)
    {
        if (0==(root->left) && 0==(root->right))
        {
            printf("%d %d\n", root->data, root->high);
        }
        printNode(root->left);
        printNode(root->right);
    }
}


