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
        root = insert(root,data); // @@ The return value of insert is not assigned back to root. Although root is NULL initially and doesn't change in main, for subsequent inserts or if root was not NULL, this would fail. More critically, in the specific test case where n=1, root remains NULL because the new node created in insert is returned but not captured by the caller's root variable.
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
    if(root == NULL) return; // @@ Missing null check for root. If root is NULL (which it is in the buggy main because the return value wasn't assigned), accessing root->lchild causes a segmentation fault (Runtime Error).
    if(root->lchild==NULL&&root->rchild==NULL)
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