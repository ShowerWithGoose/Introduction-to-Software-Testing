#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *lchild,*rchild;
} BSTNode,*PNode;

PNode insertBST(int data,PNode root) {
    if(root == NULL) {
        root = (PNode)malloc(sizeof(BSTNode));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    if(data < root->data)
        root->lchild = insertBST(data,root->lchild);
    else
        root->rchild = insertBST(data,root->rchild);
    return root;
}

void find_leaf(PNode root,int depth) {
    if(root==NULL) return; // @@ The function does not check if root is NULL before accessing its members, causing a Runtime Error when called on empty children of leaf nodes or an empty tree.
    if(root->lchild==NULL&&root->rchild==NULL) {
        printf("%d %d\n",root->data,depth);
        return ;
    }
    find_leaf(root->lchild,depth+1);
    find_leaf(root->rchild,depth+1);
}

int main() {
    int n,depth=1;
    scanf("%d",&n);
    int data;
    int i;
    PNode root = NULL; //二叉查找树根节点
    for(i=0; i<n; i++) { //创建二叉查找树
        scanf("%d",&data);
        root = insertBST(data,root);
    }
    find_leaf(root,depth);
    return 0;
}