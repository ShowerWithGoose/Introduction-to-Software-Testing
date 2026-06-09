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
            j++;
        p -> left = insertnum(p -> left, a, h + 1);
    }
    else
    {
        if(p -> right == NULL && p -> left == NULL)
            j++;
        p -> right = insertnum(p -> right, a, h + 1);
    }
    if(j == 1)
        root = p; // @@ [Error: This incorrectly updates root every time j==1, but j is modified during recursion, so root may be set to a non-root node. Also, the global variable j is used incorrectly to track height, causing height values to be wrong.]
    printf("%d %d\n", p -> data, p -> high); // @@ [Error: This print statement outputs every node during insertion, which is not required by the problem and will produce extra output.]
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
        insertnum(root, a, 1); // @@ [Error: The first argument should be root, but root is initially NULL and never updated correctly in main, so the tree is not built properly.]
    }
    preorder(root);
}