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
    if(root->lchild==NULL&&root->rchild==NULL) { // @@ [Error: The function does not check if root is NULL before accessing its members. If the tree is empty (root is NULL), this will cause a segmentation fault. Additionally, the traversal logic is incorrect: it should only print leaf nodes and recursively traverse left and right subtrees, but the current code will crash if a node has only one child because it calls find_leaf on a NULL pointer without a NULL check.]
        printf("%d %d\n",root->data,depth);
        return ;
    }
    find_leaf(root->lchild,depth+1); // @@ [Error: This will cause a segmentation fault if root->lchild is NULL, because the function does not check for NULL at the start.]
    find_leaf(root->rchild,depth+1); // @@ [Error: Same issue as above; no NULL check before accessing root->rchild.]
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