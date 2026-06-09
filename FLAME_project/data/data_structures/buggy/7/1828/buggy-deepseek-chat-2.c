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
    shuchu(root->lchild,tall++); // @@ [Error: Using post-increment tall++ passes the original value (tall) to the recursive call, not tall+1. This causes the height to not increase correctly. Should be tall+1.]
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ [Error: Same issue as above; tall++ passes the current tall value instead of tall+1. Also, the logic is flawed: the else if below will only execute if root->rchild is NULL, but if root->lchild is not NULL, the first if executes and then the else if is skipped due to the else, causing leaf nodes with only a left child to be missed. The correct structure should use separate if statements without else.]
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ [Error: The else if is attached to the previous if, meaning this condition is only checked when root->rchild is NULL. If root->lchild is not NULL, the first if executes and the else if is skipped, so leaf nodes with only a left child are not printed. Should be a separate if statement.]
    printf("%d %d\n",root->data,tall);
}