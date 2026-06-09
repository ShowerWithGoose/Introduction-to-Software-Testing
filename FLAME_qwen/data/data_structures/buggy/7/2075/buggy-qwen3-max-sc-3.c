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
        leaves_height(root->left,h+1); @@ [When root is NULL, calling leaves_height on NULL with h+1 leads to infinite recursion or crash; also, the logic fails to traverse non-leaf nodes properly because it only recurses in the else branch, skipping traversal when root is a leaf.]
        leaves_height(root->right,h+1); @@ [Same issue as above: if root is a leaf, this function prints and returns without recursing, which is correct, but if root is not a leaf, it recurses—but the condition structure causes double increment of height and incorrect handling when one child is NULL and the other isn't. More critically, when root is NULL, isleave(root) dereferences NULL, causing undefined behavior.]
    }
}
int isleave(BTNnodeptr root)
{
    if(root->left==NULL&&root->right==NULL)return 1; @@ [If root is NULL, this line dereferences a null pointer, leading to undefined behavior (likely segmentation fault). The function should first check if root is NULL before accessing its members.]
    return 0;
}