#include <stdio.h>
#include <stdlib.h> 
typedef struct BiTNode
{
   int Data;
   int high;
   struct BiTNode *Left,*Right;
}BNode,*BinTree;

BinTree Insert( BinTree BST, int X, int len )
{
    len++;
	if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree)malloc(sizeof(BNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
        BST->high=len;
    }
    else { /* 开始找要插入元素的位置 */
        if( X < BST->Data )
            BST->Left = Insert( BST->Left, X,len );   /*递归插入左子树*/
        else  if( X >= BST->Data )
            BST->Right = Insert( BST->Right, X,len ); /*递归插入右子树*/
        /* else X已经存在，什么都不做 */
    }
    return BST;
}


void PreorderTraversal( BinTree BT )
{
    if( BT ) 
	{
    	if(BT->Left==NULL&&BT->Right==NULL)
		{
    		printf("%d %d\n", BT->Data,BT->high );
		}
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}
//前序 
int main()
{
    int i, item,n,len;
    BinTree root=NULL;
    scanf("%d",&n);
	for(i=0; i<n; i++){ //构造一个有n个元素的BST树
         scanf("%d", &item);
         len=0;
         root = Insert(root,item,len);
     }
    PreorderTraversal(root); 
    return 0;
}









