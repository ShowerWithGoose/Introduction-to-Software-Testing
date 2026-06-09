#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
struct tree
{
    int num;
    struct tree *left;
    struct tree *right;
};
struct tree *root;
void in_tree(int a, struct tree *p)
{
    if (a < p->num && p->left == NULL)
    {
        p->left = (struct tree *)malloc(sizeof(struct tree));
        p = p->left;
        p->left = NULL;
        p->right = NULL;
        p->num = a;
    }
    else if (a >= p->num && p->right == NULL)
    { 
        p->right = (struct tree *)malloc(sizeof(struct tree));
        p = p->right;
        p->left = NULL;
        p->right = NULL;
        p->num = a;
    }
    else if (a < p->num)
        in_tree(a, p->left);
    else
        in_tree(a, p->right);
}
void dlr(struct tree *root, int height)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            printf("%d %d\n", root->num, height);
        else
        {
            dlr(root->left, height + 1);
            dlr(root->right, height + 1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    root = (struct tree *)malloc(sizeof(struct tree));
    scanf("%d", &(root->num));
    root->left = NULL;
    root->right = NULL;
    int inp;
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d",&inp);
        in_tree(inp, root);
    }
    dlr(root, 1);
    return 0;
}
