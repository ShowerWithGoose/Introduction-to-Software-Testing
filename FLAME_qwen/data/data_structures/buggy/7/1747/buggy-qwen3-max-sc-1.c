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
    find_leaf(root->lchild,depth+1); // @@ [Potential null pointer dereference: if root->lchild is NULL, the recursive call will pass NULL, and in the next call, accessing root->lchild will crash]
    find_leaf(root->rchild,depth+1); // @@ [Potential null pointer dereference: same issue as above for right child]
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
    find_leaf(root,depth); // @@ [If n is 0, root is NULL, passing NULL to find_leaf will cause a segmentation fault when accessing root->lchild]
    return 0;
}