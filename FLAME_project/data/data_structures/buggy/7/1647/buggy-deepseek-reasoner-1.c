#include<stdio.h>
#include<stdlib.h>
typedef struct bstTree{
    int data;
    struct bstTree *lChild,*rChild;
}node;
typedef node* bst;

bst insert(bst root , int num)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->data = num;
        root->lChild = NULL;
        root->rChild = NULL;
        return root;
    }
    else
    {
        if(num > root->data) // @@ Should be >= to place equal numbers to the right child.
        {root->rChild = insert(root->rChild,num);}
        else
        {root->lChild = insert(root->lChild,num);}
        return root;
    }
}

void printLeaves(bst root,int height)
{
    if(root->lChild==NULL && root->rChild==NULL)
    {
        printf("%d %d\n",root->data,height);
        return ;
    }
    else
    {
        if(root->lChild!=NULL)
        {
            printLeaves(root->lChild,height+1);
        }
        if(root->rChild!=NULL)
        {
            printLeaves(root->rChild,height+1);
        }
    }
}

int main()
{
    int i,n,number;
    bst root = NULL;
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        scanf("%d",&number);
        root = insert(root , number);
    }
    printLeaves(root,1);
    return 0;
}