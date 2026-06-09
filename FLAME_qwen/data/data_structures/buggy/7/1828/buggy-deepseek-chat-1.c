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
    scanf("%d\n",&n); // @@ The format string should be "%d" without the newline, as the newline may cause input issues.
    struct tnode *root=NULL;
    while(n--)
    {
        scanf("%d",&a);
        root=create(root,a);
    }
    int tall=1;
    shuchu(root,tall); // @@ The function shuchu is called before it is defined; a forward declaration or reordering is needed.
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ The increment operator tall++ changes the value of tall for subsequent calls; should use tall+1 instead to pass the correct height.
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ Same issue as above; should use tall+1 instead of tall++.
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ The else if is attached to the previous if, causing incorrect logic; should be a separate if statement.
    printf("%d %d\n",root->data,tall);
}