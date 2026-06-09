#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    int val;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
}*treePtr,tree;
struct value
{
    int val;
    int height;
};
void preOrder(treePtr t)
{
    if(t!=NULL)
    {
        if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->val,t->height);
        preOrder(t->left);
        preOrder(t->right);
    }
}
int main()
{
    treePtr root=(treePtr)malloc(sizeof(tree)),ptr;
    int n;
    struct value currVal;
    scanf("%d%d",&n,&(root->val));
    root->height=1;
    root->left=NULL;
    root->right=NULL;
    for(int i=1;i<n;++i)
    {
        ptr=root;
        scanf("%d",&currVal.val);
        while(1)
        {
            if(currVal.val<ptr->val)
            {
                currVal.height=ptr->height+1;
                if(ptr->left) ptr=ptr->left;
                else
                {
                    ptr->left=(treePtr)malloc(sizeof(tree));
                    ptr=ptr->left;
                    ptr->val=currVal.val;
                    ptr->height=currVal.height;
                    ptr->left=NULL;
                    ptr->right=NULL;
                    break;
                }
            }
            else if(currVal.val>=ptr->val)
            {
                currVal.height=ptr->height+1;
                if(ptr->right) ptr=ptr->right;
                else
                {
                    ptr->right=(treePtr)malloc(sizeof(tree));
                    ptr=ptr->right;
                    ptr->val=currVal.val;
                    ptr->height=currVal.height;
                    ptr->left=NULL;
                    ptr->right=NULL;
                    break;
                }
            }
        }
    }
    preOrder(root);
    return 0;
}

