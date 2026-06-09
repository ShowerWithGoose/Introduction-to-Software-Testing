#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node *left;
    struct node *right;
} tree;
tree *insert(tree *p, int lol);
void search(tree *dnf, int level);
int main()
{
    tree *root = NULL;
    int n ,x;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    search(root, 1);
    return 0;
}

tree *insert(tree *p,int lol)
{
    if(p==NULL)
    {
        p = (tree *)malloc(sizeof(tree));
        p->num = lol;
        p->left = NULL;
        p->right = NULL;
    }
    else if(lol >= p->num)
        p->right = insert(p->right, lol);
    else
        p->left = insert(p->left, lol);
    return p;
}

void search(tree *dnf, int level)
{
    if(dnf != NULL)
    {
        if(dnf->left == dnf->right && dnf->left == NULL)
            printf("%d %d\n", dnf->num,level);
        search(dnf->left, level+1);
        search(dnf->right, level+1);
    }
}


