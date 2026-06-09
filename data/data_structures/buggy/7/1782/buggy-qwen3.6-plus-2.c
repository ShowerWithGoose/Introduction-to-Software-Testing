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
        if(j == 1) // @@ Incorrect condition for height assignment; height should simply be assigned the passed parameter h.
            p -> high = j;
        else
            p -> high = h;
        p -> left = p -> right = NULL;
    }
    else if(a < p -> data)
    {
        if(p -> right == NULL && p -> left == NULL) // @@ Incorrect logic for height tracking; height is correctly passed as h+1 in recursive calls, making this increment unnecessary and wrong.
            j++;
        p -> left = insertnum(p -> left, a, h + 1);
    }
    else
    {
        if(p -> right == NULL && p -> left == NULL) // @@ Same incorrect logic as above; height tracking via global j is flawed.
            j++;
        p -> right = insertnum(p -> right, a, h + 1);
    }
    if(j == 1) // @@ Incorrect condition for updating root; root should be updated when it is initially NULL, not based on j.
        root = p;
    printf("%d %d\n", p -> data, p -> high); // @@ This prints every node during insertion, violating the output format which requires only leaf nodes to be printed at the end.
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
        insertnum(root, a, 1); // @@ The return value is ignored, so the global root pointer is never updated after the first insertion, causing preorder to receive NULL.
    }
    preorder(root);
}