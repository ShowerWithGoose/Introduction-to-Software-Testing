#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

typedef struct Node{
    int num;
    int height;
    struct Node *left;
    struct Node *right;
}tree;
int n, m, i, branc;

tree *insertBST(tree *root, int m, int branc)
{
    branc++;
    if(root == NULL)
    {
        root = (tree*)malloc(sizeof(tree));
        root->num = m;
        root->height = branc;
        root->left = root->right = NULL;
    }
    else if(m < root->num)
        root->left = insertBST(root->left, m, branc);
    else if(m >= root->num)
        root->right = insertBST(root->right, m, branc);
    return root;
}

void output(tree *root)
{
    if (root != NULL)
    {
        if ((root->left == NULL) && (root->right == NULL))
        {
            printf("%d %d\n", root->num, root->height);
        }
        output(root->left);
        output(root->right);
    }
}

int main()
{
    scanf("%d", &n);
    tree *root = NULL;
    for(i=0;i<n;i++)
    {
        branc = 0;
        scanf("%d", &m);
        root = insertBST(root, m, branc);
    }
    output(root);
    return 0;
}

