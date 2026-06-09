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
    printf("%d\n", n); // @@ [Error: This line prints the value of n, which is not required by the problem specification. The output should only contain leaf node values and heights, not the input count.]
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        printf("%d ", m); // @@ [Error: This line prints each input value, which is not required by the problem specification. The output should only contain leaf node values and heights.]
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
            q->h = 2; // @@ [Error: The height of a new node should be determined by its position in the tree, not hardcoded as 2. The height should be calculated based on the parent's height plus one.]
            q->llink = NULL;
            q->rlink = NULL;
            insert(root,q);
        }
    }
    printf("\n"); // @@ [Error: This line prints a newline, which is not required by the problem specification. The output should only contain leaf node values and heights.]
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
            p->h++; // @@ [Error: Incrementing p->h here is incorrect because p is the new node being inserted, and its height should be set relative to the root, not incremented incrementally. The height should be passed as a parameter or calculated from the parent's height.]
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
            p->h++; // @@ [Error: Same issue as above; incrementing p->h here is incorrect for the same reason.]
            insert(r->rlink, p);
        }
    }
}
void print(tree* r)
{
    if (r->llink == NULL && r->rlink == NULL)
        printf("%d %d\n", r->value, r->h);
    else if(r!=NULL) // @@ [Error: The condition `r!=NULL` is redundant here because the outer if already checks for NULL implicitly via the condition. Additionally, the order of checks is wrong; the NULL check should come first to avoid dereferencing a NULL pointer.]
    {
        if(r->llink!=NULL)print(r->llink);
        if(r->rlink!=NULL)print(r->rlink);
    }
    return;
}