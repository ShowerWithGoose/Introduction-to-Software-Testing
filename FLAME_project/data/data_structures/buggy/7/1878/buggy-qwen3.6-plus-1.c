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
        root = insert(root,data); // @@ The return value of insert is not assigned back to root. Although root is NULL initially and stays NULL if insert doesn't update the caller's pointer, the primary issue here is that `insert` returns the new node, but in `main`, the result is ignored. Since `root` is passed by value, `insert` cannot modify `root` in `main` directly. However, since `root` is initialized to NULL, the first call returns a new node which is lost. Subsequent calls pass NULL again (since root is still NULL) or crash if root was somehow set. Wait, `root` is local. `insert` takes `bst root` (which is a pointer). Inside `insert`, if `root` is NULL, it mallocs and returns. But in `main`, `insert(root,data)` is called without assignment. So `root` in `main` remains NULL. Then `printleaf(NULL, 1)` is called.
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
    if(root == NULL) return; // @@ Missing null check for root. If the tree is empty (root is NULL), accessing root->lchild causes a segmentation fault (Runtime Error).
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