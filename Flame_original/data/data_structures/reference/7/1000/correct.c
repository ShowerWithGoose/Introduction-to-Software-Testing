#include <stdio.h>
#include <stdlib.h>
#define SN struct Node
int N,v;
struct Node
{
    int val,hi;
    SN *left,*right;
};
SN *root;

SN* ins(SN *x,int val,int hi)
{
    if(x==NULL)
    {
        x=(SN*)malloc(sizeof(SN));
        x->hi=hi;
        x->val=val;
        x->left=NULL;
        x->right=NULL;
        return x;
    }
    if(val<x->val) x->left=ins(x->left,val,hi+1);
    else x->right=ins(x->right,val,hi+1);
    return x;
}

void dfs(SN* x)
{
    if(x==NULL) return;
    if(x->left==NULL&&x->right==NULL)
    {
        printf("%d %d\n",x->val,x->hi);
        return;
    }
    dfs(x->left);dfs(x->right);
}

void dfs_free(SN* x)
{
    if(x==NULL) return;
    dfs_free(x->left);dfs_free(x->right);
    free(x);
    return;
}

int main()
{
    root=NULL;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&v);
        root=ins(root,v,1);
    }
    dfs(root);
    dfs_free(root);
    return 0;
}
