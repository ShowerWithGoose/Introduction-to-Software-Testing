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
    shuchu(root,tall); // @@ The function 'shuchu' is used before it is declared or defined. In C, functions should be declared before use, or defined before main. Also, the logic inside shuchu has errors regarding height calculation and leaf node detection.
    return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall) // @@ The parameter 'tall' is passed by value. Using 'tall++' in the recursive calls passes the original value, not the incremented one, to the next level. It should be 'tall + 1'. Furthermore, the structure of if-else prevents correct traversal. If left child exists, it recurses left. Then, if right child exists, it recurses right. The 'else if' for printing leaves is only attached to the right child check. This means if a node has a left child but no right child, it will recurse left, then skip the right recursion, and then fail to print itself as a leaf (if it were one, but it has a left child so it's not a leaf). More critically, if a node is a leaf, both lchild and rchild are NULL. The first if fails. The second if fails. The else if executes. This part is technically okay for leaves. However, the height calculation is wrong because 'tall++' post-increment returns the old value. So all nodes receive the same height as their parent in the recursive call argument effectively if not careful, but specifically here, `shuchu(root->lchild, tall++)` passes the current `tall`, then increments local `tall`. The child receives the unincremented height. This results in incorrect heights. It should be `tall + 1`.
{
    if(root->lchild!=NULL)
    shuchu(root->lchild,tall++); // @@ Error: 'tall++' passes the current value of tall to the recursive call, then increments the local variable. The child node should receive 'tall + 1'. Using 'tall++' means the height doesn't increase correctly for the children.
    if(root->rchild!=NULL)
    shuchu(root->rchild,tall++); // @@ Error: Same as above. 'tall++' should be 'tall + 1'. Additionally, this 'if' is independent of the previous one, which is correct for traversal, but the height propagation is broken.
    else if(root->rchild==NULL&&root->lchild==NULL) // @@ Logic Error: This 'else if' is associated with the immediately preceding 'if (root->rchild!=NULL)'. This means the leaf check is only performed if 'root->rchild == NULL'. If a node has a left child but no right child, the first 'if' executes, the second 'if' fails, and this 'else if' executes. Since the node has a left child, it is NOT a leaf, but the condition 'root->lchild==NULL' will fail, so it won't print. This seems okay for that specific case. However, consider a node with NO left child but a right child. First 'if' fails. Second 'if' succeeds, recurses right. The 'else if' is skipped. This is correct. Consider a leaf node. First 'if' fails. Second 'if' fails. 'else if' executes. Condition is true. Prints. This seems logically okay for identification of leaves ONLY IF the height was correct. But wait, if a node has a left child, we recurse left. Then we check right. If no right, we check else-if. The else-if checks if it's a leaf. It's not (has left). So it doesn't print. Correct. The main issue remains the height calculation and the fact that function declaration order is problematic in standard C without prototypes.
    printf("%d %d\n",root->data,tall);
}