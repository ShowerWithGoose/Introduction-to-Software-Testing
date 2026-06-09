#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left, *right;
}BT;

BT *BSTinsert(BT *Tptr, int data)
{
    if (!Tptr)
    {
        Tptr = (BT *)malloc(sizeof(BT));
        Tptr->data = data;
        Tptr->left = Tptr->right = NULL;
    }
    else
    {
        if (data < Tptr->data)
        {
            Tptr->left = BSTinsert(Tptr->left, data);
            Tptr->left->height = Tptr->height+1;
        }

        else
        {
            Tptr->right = BSTinsert(Tptr->right, data);
            Tptr->right->height = Tptr->height+1;
        }
    }
    return Tptr;
}

void InOrderVisit(BT *Tptr)
{
    if (Tptr)
    {
        InOrderVisit(Tptr->left);
        if (!Tptr->left&&!Tptr->right)
        {
            printf("%d %d\n", Tptr->data, Tptr->height);
        }
        InOrderVisit(Tptr->right);
    }
}

int main()
{
    int n, item;
    BT *SortTree = (BT *)malloc(sizeof(BT));
    scanf("%d", &n);
    scanf("%d", &item);
    SortTree->data = item;
    SortTree->height = 1;
    SortTree->left = SortTree->right = NULL;

    for (int i = 0;i < n-1;i ++)
    {
        scanf("%d", &item);
        SortTree = BSTinsert(SortTree, item);
    }

    InOrderVisit(SortTree);

    return 0;
}



