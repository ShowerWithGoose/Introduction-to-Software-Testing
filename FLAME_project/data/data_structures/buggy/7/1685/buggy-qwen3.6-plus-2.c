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
        if (a > (*root)->data) {  // @@ The problem states that left child is less than root, and right child is greater than or equal to root. This condition puts strictly greater values to the right, but fails to handle equal values correctly according to the "greater than or equal" rule for the right side. It should be `a >= (*root)->data` for right, or `a < (*root)->data` for left. Currently, if `a == (*root)->data`, it goes to the `else` block (left), which violates the rule "right child is greater than or equal". Wait, let's re-read carefully. "left child is less than the value of the root, and the value of the right child is greater than or equal to the value of the root". So if `a < root->data`, go left. If `a >= root->data`, go right. The current code goes right if `a > root->data`, and left otherwise (i.e., `a <= root->data`). This means equal values go left, which is incorrect. They should go right.
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