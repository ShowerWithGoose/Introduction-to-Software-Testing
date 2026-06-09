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
    scanf("%d\n",&n); // @@ The format string "%d\n" may cause issues; it expects a newline after the number, which can lead to incorrect input reading. Use "%d" instead.
    struct tnode *root=NULL;
    while(n--)
    {
        scanf("%d",&a);
        root=create(root,a);
    }
    int tall=1;
    shuchu(root,tall); // @@ The function shuchu is called before it is declared or defined, causing a compilation error. Move the function definition before main or add a forward declaration.
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ The post-increment tall++ passes the original value to the recursive call, not the incremented value. Use tall+1 instead.
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ Same issue as above; use tall+1 instead of tall++.
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ The else if is attached to the previous if, meaning it only executes when root->rchild is NULL, but the logic should check leaf condition independently. Use a separate if statement.
    printf("%d %d\n",root->data,tall);
}