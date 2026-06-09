#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    int high;
    struct _node *lnext, *rnext;
} Node;
typedef struct _tree
{
    Node *root;
} Tree;

void new_tree_node(Tree *tr, int temp, int high);
void new_node(Node *q, int temp, int high);
void print_tree(Node *q);

int main()
{
    Tree bst;
    bst.root = NULL;
    int i = 0, n = 0, max = 0, temp = 0, high = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        high = 0;
        scanf("%d", &temp);
        new_tree_node(&bst, temp, high);
    }
    print_tree(bst.root);
    return 0;
}

void new_tree_node(Tree *tr, int temp, int high)
{
    high = 1;
    if (!tr->root)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = temp;
        p->high = high;
        p->lnext = NULL;
        p->rnext = NULL;
        tr->root = p;
    }
    else
        new_node(tr->root, temp, high);
}
void new_node(Node *q, int temp, int high)
{
    high++;
    if (temp < q->data)
    {
        if (!q->lnext)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            p->data = temp;
            p->high = high;
            p->lnext = NULL;
            p->rnext = NULL;
            q->lnext = p;
        }
        else
            new_node(q->lnext, temp, high);
    }
    else
    {
        if (!q->rnext)
        {
            Node *p = (Node *)malloc(sizeof(Node));
            p->data = temp;
            p->high = high;
            p->lnext = NULL;
            p->rnext = NULL;
            q->rnext = p;
        }
        else
            new_node(q->rnext, temp, high);
    }
}

void print_tree(Node *q)
{
    if (!q->lnext && !q->rnext)
        printf("%d %d\n", q->data, q->high);
    else
    {
        if (q->lnext)
            print_tree(q->lnext);
        if (q->rnext)
            print_tree(q->rnext);
    }
}
