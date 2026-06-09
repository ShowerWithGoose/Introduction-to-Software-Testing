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
    printf("%d\n", n); // @@ [Unnecessary output; problem does not require printing n]
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        printf("%d ", m); // @@ [Unnecessary output; problem does not require printing input values]
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
            q->h = 2; // @@ [Incorrect initial height; height should be computed during insertion based on path length from root, not hardcoded to 2]
            q->llink = NULL;
            q->rlink = NULL;
            insert(root,q);
        }
    }
    printf("\n"); // @@ [Unnecessary newline output; problem does not require this]
    print(root);
    free(root); // @@ [Incomplete memory deallocation; only frees root, not entire tree]
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
            p->h++; // @@ [Incorrect height update; height is incremented before recursive call, but multiple increments may occur along the path leading to wrong height]
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
            p->h++; // @@ [Same issue as above; height is being modified during traversal, leading to incorrect final height]
            insert(r->rlink, p);
        }
    }
}
void print(tree* r)
{
    if (r->llink == NULL && r->rlink == NULL)
        printf("%d %d\n", r->value, r->h);
    else if(r!=NULL)
    {
        if(r->llink!=NULL)print(r->llink);
        if(r->rlink!=NULL)print(r->rlink);
    }
    return;
}