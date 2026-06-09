#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int value;
    int h;
    struct node* llink;
    struct node* rlink;
}tree;
void insert(tree* r, tree* p);
void print(tree* r);

int main()
{
    int n,m;
    tree* root=NULL, * p=NULL, * q=NULL;
    scanf("%d", &n);
    printf("%d\n", n); // @@ Unnecessary output violates the specified output format.
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        printf("%d ", m); // @@ Unnecessary output violates the specified output format.
        if (i <= 0)
        {
            p = malloc(sizeof(tree));
            root = p;
            p->value = m;
            p->h = 1;
            p->rlink = NULL;
            p->llink = NULL;
        }
        else
        {
            q = malloc(sizeof(tree));
            q->value = m;
            q->h = 2; // @@ Incorrect height initialization; height should be dynamically calculated based on the parent node's height.
            q->llink = NULL;
            q->rlink = NULL;
            insert(root,q);
        }
    }
    printf("\n"); // @@ Unnecessary output violates the specified output format.
    print(root);
    free(root);
    return 0;
}

void insert(tree* r, tree* p)
{
    if (p->value < r->value)
    {
        if (r->llink == NULL)
        {
            r->llink = p;
        }
        else
        {
            p->h++; // @@ Incorrect height update logic; height should be set to parent's height + 1 upon attachment, not incremented during recursion.
            insert(r->llink, p);
        }
    }
    else
    {
        if (r->rlink == NULL)
        {
            r->rlink = p;
        }
        else
        {
            p->h++; // @@ Incorrect height update logic; height should be set to parent's height + 1 upon attachment, not incremented during recursion.
            insert(r->rlink, p);
        }
    }
}
void print(tree* r)
{
    if (r->llink == NULL && r->rlink == NULL) // @@ Potential null pointer dereference if r is NULL; must check r != NULL before accessing members.
        printf("%d %d\n", r->value, r->h);
    else if(r!=NULL) // @@ Redundant and incorrectly ordered condition; leads to flawed traversal logic and should be replaced with a proper base case check.
    {
        if(r->llink!=NULL)print(r->llink);
        if(r->rlink!=NULL)print(r->rlink);
    }
    return;
}