#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct tree
{
    int data;
    struct tree *lc,*rc;
}tree;
tree* create(tree* root,int data)
{
    if (root==NULL)
    {
        root=(tree*)malloc(sizeof(tree));
        root->data=data;
        root->lc=NULL;
        root->rc=NULL;
    }
    else
    {
         if(data>root->data) // @@ 条件错误：应改为 if(data < root->data) 以满足左子树小于根，右子树大于等于根
        {
            root->rc=create(root->rc,data); // @@ 此处应改为左子树插入：root->lc=create(root->lc,data)
        }
        else // @@ 应处理 data >= root->data 的情况，当前意图是插入右子树
        {
            root->lc=create(root->lc,data); // @@ 此处应改为右子树插入：root->rc=create(root->rc,data)
        }
    }
    return root;
}
void print(tree* root,int hight)
{
    if (root->lc==NULL && root->rc==NULL)
    {
        printf("%d %d\n",root->data,hight);
    }
    if(root->lc!=NULL)
    {
        print(root->lc,hight+1);
    }
    if(root->rc!=NULL)
    {
        print(root->rc,hight+1);
    }
}
int main()
{
    int n;
    int a;
    int i=0;
    int data;
    tree *p=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        p=create(p,data);
    }
    print(p,1);
    return 0;
}