#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *left,*right;
}list;
list *addtree(list *root,int val)
{
    if(root==NULL)
    {
        root=(list *)malloc(sizeof(list));
        root->val=val;
        root->left=NULL;
        root->right=NULL;
    }
    else if(root->val>val)
    {
        root->left=addtree(root->left,val);
    }
    else
    {
        root->right=addtree(root->right,val);
    }
    return root;
}
list * createtree()
{
    int n;
    scanf("%d",&n);
    list *root=NULL;
    int i;
    int op;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&op);
        root=addtree(root,op);
    }
    return root;
}
void dfs(list *root,int dep)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%d %d\n",root->val,dep);
        return ;
    }
    else
    {
        dfs(root->left,dep+1);
        dfs(root->right,dep+1);
    }
}
int main()
{
    list *obj=createtree();
    dfs(obj,1);
    return 0;
}
