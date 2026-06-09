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
        T = (Bintree)malloc(sizeof(struct TreeNode));
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
        printf("%d %d\n",T->data,k+1); // @@ The height calculation is incorrect. The root height should be 1, but here k starts at 0 and k+1 gives 1 for the root, but when recursing, k is incremented before the recursive call, causing the height to be off by one. The reference program uses a global variable k that increments and decrements correctly.
    }
    else
    {
        k++; // @@ This increments k before recursing, but the height should be passed as the current node's height + 1 to children, not incremented in place. This causes the height to be incorrectly calculated for deeper nodes.
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
printf("%d\n",n); // @@ This line prints the value of n (the count) as an extra line, which is not part of the expected output. The problem only requires outputting leaf node values and heights, not the count.
for(int i=0;i<n;i++)
{
    scanf("%d",&b);
    p=InitTree(b,p);
}
BintreeFindLeaves(p,k);
return 0;
}