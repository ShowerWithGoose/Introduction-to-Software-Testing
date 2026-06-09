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
    scanf("%d\n",&n);
    struct tnode *root=NULL;
    while(n--)
    {
        scanf("%d",&a);
        root=create(root,a);
    }
    int tall=1;
    shuchu(root,tall);
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ [Error: Using post-increment tall++ passes the original value (tall) to the recursive call, not tall+1. This causes the height to not increase correctly. Should be tall+1 instead.]
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ [Error: Same issue as above; post-increment tall++ passes the current tall value instead of tall+1, leading to incorrect height propagation.]
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ [Error: The else if condition is logically incorrect. It only executes when root->rchild is NULL, but the previous if for left child may have already executed. This means leaf nodes with a left child but no right child will not be printed. Should use a separate if statement without else.]
    printf("%d %d\n",root->data,tall);
}