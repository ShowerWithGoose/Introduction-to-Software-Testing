#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int i = 0, n = 0, a = 0, j = 1; // @@ Global variable j is incorrectly used to track height, causing wrong height calculations across recursive calls.
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
        if(j == 1) // @@ Condition based on j is incorrect; height should always be assigned the passed parameter h.
            p -> high = j; // @@ Should be p->high = h; to correctly set the node's height.
        else
            p -> high = h;
        p -> left = p -> right = NULL;
    }
    else if(a < p -> data)
    {
        if(p -> right == NULL && p -> left == NULL) // @@ Incorrectly checks leaf status to increment j, which corrupts height tracking.
            j++; // @@ Should be removed; height is correctly passed down via the h parameter.
        p -> left = insertnum(p -> left, a, h + 1);
    }
    else
    {
        if(p -> right == NULL && p -> left == NULL) // @@ Same incorrect logic as above.
            j++; // @@ Should be removed.
        p -> right = insertnum(p -> right, a, h + 1);
    }
    if(j == 1) // @@ Should check if root == NULL to correctly initialize the global root pointer.
        root = p;
    printf("%d %d\n", p -> data, p -> high); // @@ Outputs every node during insertion, violating the requirement to only output leaf nodes at the end.
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
        insertnum(root, a, 1); // @@ root is passed by value, so the initial assignment to root inside insertnum may not persist correctly without fixing the global update logic.
    }
    preorder(root);
}