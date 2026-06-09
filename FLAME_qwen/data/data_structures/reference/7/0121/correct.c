#include<stdio.h>
#include<stdlib.h>

typedef struct TNode *BinTree;
struct TNode
{
    int d;
    BinTree l, r;
    int h;
};
void printbst(BinTree BST)
{
    if(0!=BST) 
    {
        if((BST->l==0) && (BST->r==0))
            printf("%d %d\n", BST->d, BST->h);
        printbst(BST->l);
        printbst(BST->r);
    }
}
BinTree Insert(BinTree BST, int c)
{
    if (0==BST)
    { 
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->l = NULL;
        BST->r = NULL;
		BST->d = c;
        BST->h = 1;
    }
    else if(0!=BST)
    {
        if(BST->d>c)
        {
            BST->l = Insert(BST->l, c);
            BST->l->h = BST->h + 1;
        }
        else if(BST->d<=c)
        {
            BST->r = Insert(BST->r, c);
            BST->r->h = BST->h + 1;
        }
    }
    return BST;
}



int main()
{
    int n, x;
    BinTree BST = NULL;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        BST = Insert(BST, x);
    }
    printbst(BST);
    return 0;
}

