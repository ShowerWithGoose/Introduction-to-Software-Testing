#include<stdio.h>  
#include<stdlib.h>  
  
typedef struct node {  
    int data;  
    struct node *lchild, *rchild;  
} nod, *nodp;  
  
void insert(nodp *root, int a) {  
    if (*root == NULL) {  
        *root = (nodp)malloc(sizeof(nod));  
        (*root)->data = a;   
        (*root)->lchild = NULL;  
        (*root)->rchild = NULL;  
    } else {  
        if (a > (*root)->data) { // @@ Incorrect comparison: for BST with left<root and right>=root, this condition sends values greater than root to the right, but equal values go to the left (due to else), which violates the rule. Should be `if (a < (*root)->data)` to send smaller values left, else (>=) right.
            insert(&(*root)->rchild, a);  
        } else {  
            insert(&(*root)->lchild, a);  
        }  
    }  
}  
  
void print(nodp root, int depth) {  
    if (root == NULL) return;  
  
    if (root->lchild == NULL && root->rchild == NULL) {  
        printf("%d %d\n", root->data, depth);  
    }  
  
    print(root->lchild, depth + 1);  
    print(root->rchild, depth + 1);  
}  
  
int main() {  
    int n, i, a;  
    nodp root = NULL;  
    scanf("%d", &n);  
  
    for (i = 0; i < n; i++) {  
        scanf("%d", &a);  
        insert(&root, a);  
    }  
  
    print(root, 1);  // 从根节点开始的深度为1  
    return 0;  
}