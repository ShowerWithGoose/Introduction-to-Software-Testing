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
    scanf("%d\n",&n); // @@ [Using "%d\n" can cause unexpected blocking or behavior; it's safer to use just "%d" as in the reference program. However, this is not the main cause of WA.]
    struct tnode *root=NULL;
    while(n--)
    {
        scanf("%d",&a);
        root=create(root,a);
    }
    int tall=1;
    shuchu(root,tall); // @@ [Function 'shuchu' is called before its declaration, which may cause implicit declaration warning but not necessarily runtime error in older C standards. Still, not best practice. The real bug is inside 'shuchu'.]
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ [Using 'tall++' passes the current value of tall and then increments it locally, but the incremented value is not used in the right subtree call. This causes incorrect height tracking. Should pass 'tall + 1' instead.]
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ [Same issue: 'tall++' does not correctly propagate increased height to the recursive call. Also, after the left call, 'tall' might have been incremented, leading to inconsistent height values.]
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ [This 'else if' means that if a node has a left child but no right child, it won't be recognized as a leaf even if it should be (but actually, leaf must have both children NULL). However, the bigger issue is that the condition for printing is only checked when the right child is NULL, missing cases where left is NULL and right exists? Actually, no: because if left exists, first if runs; if right exists, second if runs. But the logic structure is flawed because the leaf check should be independent. More critically, the function doesn't handle the case where a node has only a left child — it would skip the leaf check entirely because the second 'if' fails and it's not in an 'else'. But actually, the real problem is the use of 'else if' — it should be a plain 'if' for leaf check. However, the primary bug is the height passing with post-increment.]
    printf("%d %d\n",root->data,tall);
}