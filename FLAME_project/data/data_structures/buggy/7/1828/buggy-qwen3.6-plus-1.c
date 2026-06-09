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
    shuchu(root,tall); // @@ The function 'shuchu' is used before it is declared or defined. In C, functions must be declared before use, or defined before the calling function. Also, the logic inside shuchu has errors regarding height calculation and leaf node detection.
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall) // @@ The parameter 'tall' is passed by value. Using 'tall++' passes the current value to the recursive call but increments the local copy afterwards, which doesn't affect the sibling branch or the current level's logic correctly for height tracking. It should pass 'tall + 1'.
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ Using post-increment 'tall++' here is incorrect for passing the height of the child node. It passes the current 'tall' and then increments the local variable. It should be 'tall + 1'. Furthermore, this structure fails to handle cases where a node has only a right child correctly in conjunction with the else-if below.
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ Same error as above. 'tall++' should be 'tall + 1'.
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ This 'else if' is attached to the previous 'if (root->rchild!=NULL)'. This means a leaf node check is only performed if the right child IS NULL. However, if a node has a left child but no right child, the first 'if' executes, the second 'if' fails, and the 'else if' checks for leaf status. But if a node is a leaf (both NULL), the first 'if' fails, the second 'if' fails, and the 'else if' correctly identifies it. The main issue is that the height 'tall' has not been incremented correctly for the children, and the logic for detecting leaves is fragile. More importantly, the height reported is wrong because 'tall' wasn't incremented properly in the recursive calls. The expected output shows specific heights based on depth. The reference program uses pre-increment or explicit +1 in the call. Here, even if we fix the increment, the 'else if' logic is slightly off because it depends on the previous if. A simple 'if' for leaf check is better. But the primary error causing Wrong Answer is the height calculation.
    printf("%d %d\n",root->data,tall);
}