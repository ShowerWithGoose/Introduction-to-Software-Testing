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
    if(root->lchild==NULL&&root->rchild==NULL) {
        printf("%d %d\n",root->data,depth);
        return ;
    }
    if(root->lchild != NULL) // @@ [Calling find_leaf on NULL pointer when left child is NULL leads to runtime error]
        find_leaf(root->lchild,depth+1);
    if(root->rchild != NULL) // @@ [Calling find_leaf on NULL pointer when right child is NULL leads to runtime error]
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
    if(root != NULL) // @@ [If n is 0, root remains NULL and calling find_leaf causes runtime error; but test case has n=10 so this may not be the issue here. However, the real issue is in find_leaf recursing into NULL children without checking.]
        find_leaf(root,depth);
    return 0;
}