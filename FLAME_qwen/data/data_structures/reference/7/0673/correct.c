#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode* SearchTree;
typedef struct TreeNode {
    SearchTree left;
    SearchTree right;
    int data;
}*Bintree;
int j=1;
Bintree InitTree(int x, SearchTree T) {
    if (T == NULL) {
        T = (Bintree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            return 0;
        else {
            T->data = x;
            T->right = NULL;//先右节点，在左节点
            T->left = NULL;
        }
    }
    else if (x < T->data) {
        T->left = InitTree(x, T->left);
    }
    else if (x >= T->data) {
        T->right = InitTree(x, T->right);
    }
return T;
}
//先序遍历
void Preorder(Bintree p)
{
    if (p == NULL)
    return;
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d\n", p->data,j);
        j++;
        Preorder(p->left);
        Preorder(p->right);
        j--;
}
int main() {
    Bintree p = NULL;
    int a[100];
    int num;
    scanf("%d", &num);
    int i;
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
        p=InitTree(a[i], p);
    }
    Preorder(p);
    return 0;
}


