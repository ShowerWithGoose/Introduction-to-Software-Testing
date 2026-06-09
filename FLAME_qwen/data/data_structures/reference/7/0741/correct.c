#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000000
#define ll long long

// 定义元素的类型
typedef int ElementType; 


// 链式存储二叉树
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    int depth;
    BinTree Left;
    BinTree Right;
};

// 求整棵树深度
int GetDepth(BinTree T){
    int ldep,rdep;
    if(!T)              return 0;
    else{
        ldep=GetDepth(T->Left);
        rdep=GetDepth(T->Right);
        if(ldep>rdep)   return ldep+1;
        else            return rdep+1;
    }
}

// 创建、插入二叉搜索树
BinTree Insert(ElementType X,BinTree BST,int depth){
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TreeNode));
        BST->Data=X;
        BST->depth=depth;
        BST->Left=BST->Right=NULL;
    }else{
        if(X<BST->Data){
            BST->Left=Insert(X,BST->Left,depth+1);
        }else{
            BST->Right=Insert(X,BST->Right,depth+1);
        }
    }
    return BST;
}

// 输出所有叶子结点
void PreOrderPrintLeaves(BinTree BT){
    if(BT){
        if(!BT->Left&&!BT->Right)
            printf("%d %d\n",BT->Data,BT->depth);
            // 注意输出数据类型
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}





int main() {
    // 一定初始化为NULL
    BinTree BST=NULL;

    int n,x;
    scanf("%d",&n);
    while(n){
        scanf("%d",&x);
        BST=Insert(x,BST,1);
        n--;
    }
    PreOrderPrintLeaves(BST);
    
    
	return 0;
}
