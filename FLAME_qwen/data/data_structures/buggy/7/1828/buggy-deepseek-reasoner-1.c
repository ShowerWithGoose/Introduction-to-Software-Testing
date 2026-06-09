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
    scanf("%d\n",&n); // @@ Error: newline in format string can cause unintended input skipping; should be "%d" without newline.
    struct tnode *root=NULL;
    while(n--)
    {
        scanf("%d",&a);
        root=create(root,a);
    }
    int tall=1;
    shuchu(root,tall); // @@ Error: function 'shuchu' is called before it is defined; implicit declaration leads to compilation error or undefined behavior.
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ Error: post-increment 'tall++' passes the current value (not tall+1) to the recursive call; should be 'tall+1'.
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ Error: same as above; should be 'tall+1'.
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ Error: 'else if' is attached to the previous 'if'; if left child exists but right child does not, the leaf condition is skipped. Should be a separate 'if' statement.
    printf("%d %d\n",root->data,tall);
}