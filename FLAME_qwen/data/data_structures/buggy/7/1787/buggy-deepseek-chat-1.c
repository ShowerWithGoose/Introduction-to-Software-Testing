#include<stdio.h>
typedef struct TreeNode* SearchTree;
typedef struct TreeNode {
    SearchTree left;
    SearchTree right;
    int data;
}*Bintree;

Bintree InitTree(int x, SearchTree T) {
    int i = 0;
    if (T == NULL) {
        T = (Bintree)malloc(sizeof(struct TreeNode)); // @@ Missing #include <stdlib.h> for malloc
        if (T == NULL)
            return 0;
        else {
            T->data = x;
            T->right = NULL;//先右节点，在左节点
            T->left = NULL;
        }
    }
    else if (x <=T->data) {
        T->left = InitTree(x, T->left);
    }
    else if (x > T->data) {
        T->right = InitTree(x, T->right);
    }
    else
        printf("%d has inserted\n", x);
    return T;
}
void BintreeFindLeaves(SearchTree T,int k)
{
    if(T->right==NULL&&T->left==NULL)
    {
        printf("%d %d\n",T->data,k+1);
    }
    else
    {
        k++;
        if(T->left!=NULL)
        BintreeFindLeaves(T->left,k);
        if(T->right!=NULL)
        BintreeFindLeaves(T->right,k);
    }
}
int main()
{
int n,b=0,k=0;
Bintree p=NULL;
scanf("%d",&n);
printf("%d\n",n); // @@ Extra output not in specification; prints n before processing leaves
for(int i=0;i<n;i++)
{
    scanf("%d",&b);
    p=InitTree(b,p);
}
BintreeFindLeaves(p,k);
return 0;
}