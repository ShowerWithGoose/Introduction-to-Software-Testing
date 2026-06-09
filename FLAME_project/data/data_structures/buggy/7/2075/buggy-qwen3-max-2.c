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
    if(root!=NULL&&isleave(root))
    {
        printf("%d %d\n",root->data,h+1);
    }
    else
    {
        leaves_height(root->left,h+1); // @@ [When root is NULL, this recursive call will dereference a NULL pointer in isleave(), causing a runtime error. The condition should check root != NULL before recursing.]
        leaves_height(root->right,h+1); // @@ [Same issue: if root is NULL, this line causes undefined behavior due to passing NULL to leaves_height and then calling isleave(NULL).]
    }
}
int isleave(BTNnodeptr root)
{
    if(root->left==NULL&&root->right==NULL)return 1; // @@ [If root is NULL, accessing root->left or root->right causes a segmentation fault. This function assumes root is not NULL, but it's called without checking in leaves_height when root may be NULL.]
    return 0;
}