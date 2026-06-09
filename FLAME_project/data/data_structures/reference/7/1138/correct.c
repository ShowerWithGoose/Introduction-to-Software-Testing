#include "stdio.h"
#include "stdlib.h"
typedef struct TNode *Position;
typedef Position BinTree;
typedef int bstType;
struct TNode{
    bstType Data;
    BinTree Left;
    BinTree Right;
};

BinTree insertBst (BinTree BST, bstType X);
BinTree deleteBst (BinTree BST, bstType X );
Position Find (BinTree BST, bstType X );
Position FindMin (BinTree BST );
Position FindMax (BinTree BST );
void PreorderTraversal(BinTree BT, int depth);

int n;
struct TNode head;
BinTree A = &head;
int main(){
    scanf("%d", &n);
    scanf("%d", &head.Data);
    for(int i = 2; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        insertBst(A, temp);
    }

    PreorderTraversal(A, 1);

    return 0;
}

BinTree insertBst(BinTree BST, bstType X)
{
    if (BST == NULL)                       // 递归终止条件
    {
        // 如果树为空，直接插入
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else
    {
        if (BST->Data > X)
        {
            /* 如果当前结点大于X，那么将该结点插到BST->Left
            返回的结点为BST->Left;
            */
            BST->Left = insertBst(BST->Left, X);
        }

        else if (BST->Data <= X)
        {
            /* 如果当前结点小于X，那么将该结点插到BST->Right
            返回的结点为BST->Right;
            */
            BST->Right = insertBst(BST->Right, X);
        }
    }
    return BST;
}

BinTree deleteBst(BinTree BST, bstType X)
{
    Position Tmp;

    if (!BST)
    {
        // 如果没有找到要删除元素
        printf("Not Found\n");
    }
    else
    {
        if (X < BST->Data)
        {
            BST->Left = deleteBst(BST->Left, X);      // 如果X比较小，递归删除左子数，返回的根节点是BST->Left
        }
        else if (X > BST->Data)
        {
            BST->Right = deleteBst(BST->Right, X);
        }
        else
        {
            // BST就是要删除节点
            if (BST->Left && BST->Right)   // 如果被删除结点有左右子儿子
            {

                Tmp = FindMin(BST->Right); // 从右子数找一个最小值的节点
                BST->Data = Tmp->Data;     // 将右子数最小值赋值给要删除根节点
                BST->Right = deleteBst(BST->Right, BST->Data);   // 从右子数中删除最小值
            }
            else
            {
                // 被删除结点有一个或无子节点,与链表的删除相同
                Tmp = BST;
                if (!BST->Left)
                {
                    // 如果没有左结点
                    BST = BST->Right;
                }
                else
                {
                    // 如果没有右节点
                    BST = BST->Left;
                }
                free(Tmp);
            }
        }
    }
    return BST;
}

Position Find(BinTree BST, bstType X)
{
    while (BST)
    {
        if (BST->Data == X)
            return BST;

        else if (BST->Data > X)
        {
            BST = BST->Left;
        }
        else
        {
            BST = BST->Right;
        }
    }
    return NULL;
}

Position FindMin(BinTree BST)
{
    while (BST)
    {
        if (!BST->Left)
        {   /* 如果已经到达二叉搜索树的最左端
			   那么此时为最小值*/
            return BST;
        }
        BST = BST->Left;
    }
    return NULL;
}

void PreorderTraversal(BinTree BT, int depth)
{
    if (BT == NULL)    // 递归终止条件
        return;
    //printf("%d ", BT->Data);
    if(BT->Left == NULL && BT->Right == NULL){
        printf("%d %d\n",BT->Data, depth);
    }
    PreorderTraversal(BT->Left, depth + 1);
    PreorderTraversal(BT->Right, depth + 1);
}
