#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode* SearchTree;
typedef struct TreeNode {
    SearchTree left;
    SearchTree right;
    int data;
}*Bintree;
int k=1;
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
void BintreeFindLeaves(Bintree p)
{
    if (p == NULL)
    return;
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d\n", p->data,k);
        k++;
        BintreeFindLeaves(p->left);
        BintreeFindLeaves(p->right);
        k--;
}
int main() {
    Bintree p = NULL;
    int b[100];
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        p=InitTree(b[i], p);
    }
    BintreeFindLeaves(p);
    return 0;
}


