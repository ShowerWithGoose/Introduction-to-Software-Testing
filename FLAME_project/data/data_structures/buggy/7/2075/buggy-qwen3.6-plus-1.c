#include<stdio.h>
struct node
{
    int data;
    struct node* left,* right;
};
typedef struct node BTNnode,*BTNnodeptr;
BTNnodeptr insert(BTNnodeptr root,int item);
int isleave(BTNnodeptr root);
void leaves_height(BTNnodeptr root,int h);
int main()
{
    int i,n,item;
    BTNnodeptr root=NULL;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&item);
        root=insert(root,item);
    }
    leaves_height(root,0);
    return 0;
}
BTNnodeptr insert(BTNnodeptr root,int item)
//new root after inserting item into root
{
    if(root==NULL)
    {
        root=(BTNnodeptr)malloc(sizeof(BTNnode));
        root->data=item;
        root->left=NULL;
        root->right=NULL;
    }
    else if(item>=(root->data))
    {
        root->right=insert(root->right,item);
    }
    else if(item<(root->data))
    {
        root->left=insert(root->left,item);
    }
    return root;
}
void leaves_height(BTNnodeptr root,int h)
{
    if(root!=NULL&&isleave(root)) // @@ The function isleave is called before checking if root is NULL in the recursive calls below, but more importantly, the logic here prevents traversing children if the current node is a leaf. However, the critical error is in isleave which crashes on NULL root. But wait, the condition `root!=NULL` protects isleave. The real issue is that if root is not a leaf, it recurses. If root IS a leaf, it prints. This logic seems okay for traversal IF isleave handles NULL or root is checked. Let's look closer at isleave.
    {
        printf("%d %d\n",root->data,h+1);
    }
    else
    {
        leaves_height(root->left,h+1); // @@ If root is not a leaf, we recurse. However, if root is NULL, the first check `root!=NULL` fails, so it goes to else. Then `leaves_height(NULL, h+1)` is called. Inside that call, `root!=NULL` is false, so it goes to else again. Then `leaves_height(NULL->left...)` which is a segfault. Wait, if root is NULL, `root!=NULL` is false. It enters the `else` block. Then it calls `leaves_height(root->left, ...)` where root is NULL. Accessing `root->left` when root is NULL causes a Runtime Error (Segmentation Fault).
        leaves_height(root->right,h+1); // @@ Same as above. If root is NULL, accessing root->right crashes.
    }
}
int isleave(BTNnodeptr root)
{
    if(root->left==NULL&&root->right==NULL)return 1; // @@ This function does not check if root is NULL. If called with NULL, it crashes. Although in the current logic of leaves_height, isleave is only called if root!=NULL, the recursive calls in the else block of leaves_height pass NULL roots to leaves_height, which then tries to access members of NULL in the next recursion step or if isleave was called improperly. The primary crash source is the else block in leaves_height accessing root->left/right when root can be NULL.
    return 0;
}