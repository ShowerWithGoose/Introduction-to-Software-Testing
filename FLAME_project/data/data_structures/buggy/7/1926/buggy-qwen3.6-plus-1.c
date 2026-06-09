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
    printf("%d\n", n); // @@ [The problem does not require printing the input count 'n'. This causes extra output.]
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        printf("%d ", m); // @@ [The problem does not require printing the input values. This causes extra output.]
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
            q->h = 2; // @@ [Initializing height to 2 is incorrect for nodes that might be deeper in the tree. Height should be calculated during insertion based on parent's height.]
            q->llink = NULL;
            q->rlink = NULL;
            insert(root,q);
        }
    }
    printf("\n"); // @@ [The problem does not require printing a newline after inputs. This causes extra output.]
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
            p->h = r->h + 1; // @@ [The height of the new node should be set to parent's height + 1. Previously it was initialized to 2 in main and only incremented recursively, which is logically flawed for initial assignment.]
        }
        else
        {
            insert(r->llink, p);
        }
    }
    else
    {
        if (r->rlink == NULL)
        {
            r->rlink = p;
            p->h = r->h + 1; // @@ [The height of the new node should be set to parent's height + 1.]
        }
        else
        {
            insert(r->rlink, p);
        }
    }
}
void print(tree* r)
{
    if (r == NULL) return; // @@ [Added null check at the beginning to prevent crash. The original code checked children before checking if r itself is NULL in the recursive calls, but the base case logic was flawed.]
    if (r->llink == NULL && r->rlink == NULL)
        printf("%d %d\n", r->value, r->h);
    else
    {
        if(r->llink!=NULL)print(r->llink);
        if(r->rlink!=NULL)print(r->rlink);
    }
    return;
}