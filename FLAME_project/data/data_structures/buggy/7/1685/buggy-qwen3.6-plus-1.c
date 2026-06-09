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
        if (a > (*root)->data) {  // @@ The problem states that left child is less than root, and right child is greater than or equal to root. This condition puts strictly greater values to the right, but fails to handle equal values correctly according to the "greater than or equal to" rule for the right side. Specifically, if a == (*root)->data, it goes to the else block (left), which violates the rule that right child >= root. It should be if (a >= (*root)->data) for right, or explicitly handle the split. Given the reference logic: left < root, right >= root. So if a < root->data go left, else go right. Here, if a > root->data go right, else (a <= root->data) go left. This means equal elements go left, which contradicts the requirement "right child is greater than or equal to the value of the root".
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