#include <stdio.h>
#include <string.h>
typedef struct Tree
{
    int num;
    struct Tree *LeftTree;  //左子树
    struct Tree *RightTree; //右子树
} TreeNode, *TreeNodeP;
TreeNodeP root = NULL;
void InsertNode(TreeNodeP TreeRoot, int a)
{
    TreeNodeP NodeP;
    NodeP = (TreeNodeP)malloc(sizeof(TreeNode));
    NodeP->num = a;
    NodeP->LeftTree = NodeP->RightTree = NULL;
    if (TreeRoot == NULL)
    {
        TreeRoot = NodeP;
    }
    else if (a < TreeRoot->num)
    {
        if (TreeRoot->LeftTree == NULL)
            TreeRoot->LeftTree = NodeP;
        else
            InsertNode(TreeRoot->LeftTree, a);
    }
    else if (a >= TreeRoot->num)
    {
        if (TreeRoot->RightTree == NULL)
            TreeRoot->RightTree = NodeP;
        else
            InsertNode(TreeRoot->RightTree, a);
    }
}
int l = 1;
TreeNodeP SearchBST(TreeNodeP bst, int a)
{
    if (!bst)
        return NULL;
    else if (bst->num == a)
    {
        if (bst == root && bst->LeftTree != NULL)
        {
            l++;
            return SearchBST(bst->RightTree, a);
        }
        return (TreeNodeP)l;
    }
    else
    {
        if (bst->num > a)
        {
            l++;
            return SearchBST(bst->LeftTree, a); /*在左子树继续查找*/
        }
        else
        {
            l++;
            return SearchBST(bst->RightTree, a); /*在右子树继续查找*/
        }
    }
}
int sum, point, h;
void TraveseTreeNode(TreeNodeP Root)
{

    if (Root)
    {
        TraveseTreeNode(Root->LeftTree);
        TraveseTreeNode(Root->RightTree);
        if (Root->LeftTree == NULL && Root->RightTree == NULL)
        {
            h = SearchBST(root, Root->num);
            printf("%d %d\n", Root->num, h);
            l = 1;
        }
    }
}

int main()
{
    scanf("%d", &sum);
    for (int i = 0; i < sum; i++)
    {
        scanf("%d", &point);
        if (i == 0)
        {
            root = (TreeNodeP)malloc(sizeof(TreeNode));
            root->num = point;
            root->LeftTree = NULL;
            root->RightTree = NULL;
        }
        else
            InsertNode(root, point);
    }
    TraveseTreeNode(root);
}
