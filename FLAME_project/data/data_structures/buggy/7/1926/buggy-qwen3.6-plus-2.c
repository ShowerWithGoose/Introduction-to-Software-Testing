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
    printf("%d\n", n); // @@ [The problem does not require printing the input count n, this causes extra output]
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        printf("%d ", m); // @@ [The problem does not require printing the input values, this causes extra output]
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
            q->h = 2; // @@ [Initializing height to 2 is incorrect; the height should be determined during insertion based on the parent's height + 1. While it might be corrected in insert, initializing it here assumes all non-root nodes are at depth 2, which is wrong for deeper trees. More critically, the insert function logic below modifies p->h incorrectly.]
            q->llink = NULL;
            q->rlink = NULL;
            insert(root,q);
        }
    }
    printf("\n"); // @@ [This prints a newline due to the previous debug printf, contributing to wrong format if the debug prints were removed but this remains, or just unnecessary output.]
    print(root);
    free(root); // @@ [Freeing only the root leaks memory for the rest of the tree, though not strictly a "Wrong Answer" for output, it's bad practice. However, the primary WA causes are the print statements above and the logic errors below.]
    return 0;
}

void insert(tree* r, tree* p)
{
    if (p->value < r->value)
    {
        if (r->llink == NULL)
        {
            r->llink = p;
            p->h = r->h + 1; // @@ [The height of the new node should be set to parent's height + 1 when it becomes a child. The original code didn't set it here, relying on the initial malloc value which was wrong.]
        }
        else
        {
            p->h++; // @@ [Incrementing h recursively like this is incorrect. The height of a node is fixed based on its depth from the root. It should be calculated as parent->h + 1, not incremented by 1 for each recursive step which accumulates incorrectly if called multiple times or logic is flawed. Actually, standard BST insertion doesn't change height of existing nodes, it sets the height of the NEW node. The recursive call should just pass down, and the leaf assignment sets h = parent->h + 1.]
            insert(r->llink, p);
        }
    }
    else
    {
        if (r->rlink == NULL)
        {
            r->rlink = p;
            p->h = r->h + 1; // @@ [Same as above: height should be parent's height + 1.]
        }
        else
        {
            p->h++; // @@ [Same error as above: incorrect height calculation.]
            insert(r->rlink, p);
        }
    }
}
void print(tree* r)
{
    if (r == NULL) return; // @@ [Missing NULL check at the beginning causes crash if root is NULL or during recursion on empty children. The original code checked children before checking if r itself is valid in the else branch, but accessed r->llink/r->rlink in the first if without checking if r is NULL first.]
    if (r->llink == NULL && r->rlink == NULL)
        printf("%d %d\n", r->value, r->h);
    else if(r!=NULL)
    {
        if(r->llink!=NULL)print(r->llink);
        if(r->rlink!=NULL)print(r->rlink);
    }
    return;
}