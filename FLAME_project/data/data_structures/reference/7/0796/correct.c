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
Tree *New(Tree *root, int temp, int len)
{
    len++;
    Tree *q=(Tree *)malloc(sizeof(Tree));
    q->data = temp;
    q->left = q->right = NULL;
    q->high = len;
    if (root == NULL) first=root=q;
    else if (temp < root->data)
        root->left = New(root->left, temp, len);
    else if (temp >= root->data)
        root->right = New(root->right, temp, len);
    return root;
}
void print(Tree *root){
    if (root)
    {
        if (!(root->left) && !(root->right)) printf("%d %d\n", root->data, root->high);
        print(root->left);
        print(root->right);
    }
}
int main()
{
    Tree *root = NULL;
    int n,i,temp,len=0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        root = New(root, temp, len);
    }
    print(root);
    return 0;
}

