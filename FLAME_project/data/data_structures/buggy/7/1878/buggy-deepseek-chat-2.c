#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node* lchild;
    struct node* rchild;
};

typedef struct node* bst;
bst insert(bst root,int b_num);
void printleaf(bst root,int height);

int main()
{
    int n;
    scanf("%d",&n);
    int data;
    bst root=NULL;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(root,data); // @@ The return value of insert is not assigned to root, so root remains NULL after the first call, causing a segmentation fault when printleaf tries to access root->lchild.
    }
    printleaf(root,1);
    return 0;
}

bst insert(bst root,int b_num)
{
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
         root -> num= b_num;
        root->lchild=root->rchild=NULL;
        return root;
    }
    else
    {
        if(b_num<root->num)
        {
            root->lchild=insert(root->lchild,b_num);
        }
        else
        {
            root->rchild=insert(root->rchild,b_num);
        }
        return root;
    }
}

void printleaf(bst root,int height)
{
    if(root->lchild==NULL&&root->rchild==NULL) // @@ When root is NULL (due to the bug in main), dereferencing root causes a segmentation fault (runtime error).
    {
        printf("%d %d\n",root->num,height);
        return;
    }
    if (root -> lchild != NULL) {
        printleaf(root -> lchild, height + 1);
    }
    if (root -> rchild != NULL) {
        printleaf(root -> rchild, height + 1);
    }
}