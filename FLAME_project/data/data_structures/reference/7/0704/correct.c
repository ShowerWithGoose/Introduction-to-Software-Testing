#include <stdio.h>
#include <stdlib.h>
typedef struct BST
{
    int num;
    struct BST *lnext, *rnext;
} node;

node *InsertNode(node *Root, int data)
{
    node *p = Root;
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        p->num = data;
        p->lnext = NULL;
        p->rnext = NULL;
        return p;
    }
    else
    {
        if (data < p->num)
        {
            Root->lnext=InsertNode(p->lnext, data);
        }
        else
        {
            Root->rnext=InsertNode(p->rnext, data);
        }
        return Root;
    }
}
void Printleaf(node *leaf, int depth)
{
    if (leaf->lnext == NULL && leaf->rnext == NULL)
    {
        printf("%d %d\n", leaf->num, depth);
    }
}
void PrintLeaves(node *CurrentNode,int dep)
{
    if (CurrentNode->lnext != NULL)
    {
        PrintLeaves(CurrentNode->lnext,dep+1);
    }
    if (CurrentNode->rnext != NULL)
    {
        PrintLeaves(CurrentNode->rnext,dep+1);
    }
    Printleaf(CurrentNode, dep);
}
int main()
{
    node *root = NULL;
    int n;
    int datanum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &datanum);
        root = InsertNode(root, datanum);
    }
    PrintLeaves(root,1);
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/


