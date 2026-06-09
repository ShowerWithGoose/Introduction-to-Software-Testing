#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int i = 0, n = 0, a = 0, j = 1;
struct tree
{
    int data, high;
    struct tree *left, *right;
};
struct tree *p = NULL, *root = NULL;
struct tree *insertnum(struct tree *p, int a, int h)
{
    if(p == NULL)
    {
        p = (struct tree *)malloc(sizeof(struct tree));
        p -> data = a;
        if(j == 1)
            p -> high = j;
        else
            p -> high = h;
        p -> left = p -> right = NULL;
    }
    else if(a < p -> data)
    {
        if(p -> right == NULL && p -> left == NULL)
            j++; @@ [unnecessary increment of global j; height should be determined recursively, not by a global counter]
        p -> left = insertnum(p -> left, a, h + 1);
    }
    else
    {
        if(p -> right == NULL && p -> left == NULL)
            j++; @@ [unnecessary increment of global j; height should be determined recursively, not by a global counter]
        p -> right = insertnum(p -> right, a, h + 1);
    }
    if(j == 1)
        root = p;
    printf("%d %d\n", p -> data, p -> high); @@ [extraneous print; prints every node during insertion, not just leaf nodes; output does not match required format]
    return p;
}

void preorder(struct tree *root)
{
    if(root != NULL)
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            printf("%d %d\n", root -> data, root -> high);
        }
        preorder(root -> left);
        preorder(root -> right);
    }
}
int main()
{
    scanf("%d", &n);
    struct tree *q = NULL;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        insertnum(root, a, 1);
    }
    preorder(root);
}