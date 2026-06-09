#include<stdio.h>
#include<stdlib.h>
struct tnode{
    struct tnode *lchild,*rchild;
    int data;
};//树就是更复杂的表
//递归创建二叉树，数据储存
struct tnode*create(struct tnode*root,int a)
{
    if(root==NULL)
    {
        root=(struct tnode*)malloc(sizeof(struct tnode));
        root->data=a;
        root->lchild=NULL;
        root->rchild=NULL;
        return root;
    }
    else{
        if(a<root->data)
        root->lchild=create(root->lchild,a);
        else
        root->rchild=create(root->rchild,a);
        return root;//root是一直不变的，通过递归找存放位置。
    }
}
int main()
{
    int n;
    int a;
    scanf("%d\n",&n); // @@ [The '\n' in the format string causes scanf to wait for non-whitespace input, leading to input reading issues. It should be "%d".]
    struct tnode *root=NULL;
    while(n--)
    {
        scanf("%d",&a);
        root=create(root,a);
    }
    int tall=1;
    shuchu(root,tall); // @@ [Function 'shuchu' is called before its definition without a forward declaration, causing a compilation error in standard C.]
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ [Using 'tall++' passes the current height to the left child instead of height+1. It should be 'tall + 1'.]
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ [Using 'tall++' here passes an incorrectly incremented height to the right child. It should be 'tall + 1'.]
    else if(root->rchild==NULL&&root->lchild==NULL)
    printf("%d %d\n",root->data,tall);
}