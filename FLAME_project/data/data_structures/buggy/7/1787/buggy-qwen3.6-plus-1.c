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
    else if (x <=T->data) { // @@ The problem states left child is less than root, right child is greater than or equal. This condition puts equal values in the left subtree, which is incorrect. It should be x < T->data for left.
        T->left = InitTree(x, T->left);
    }
    else if (x > T->data) { // @@ Consequently, this branch handles strictly greater values. Since the previous condition was wrong, this logic is also misaligned with the requirement that right child >= root. It should handle x >= T->data.
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
        printf("%d %d\n",T->data,k+1); // @@ The height calculation is off. If k represents the depth of the current node (starting at 0 for root in main), the height (root=1) should be k+1. However, the recursion below increments k before calling children. Let's trace: Root called with k=0. If leaf, prints k+1=1. Correct. If not leaf, k becomes 1, calls children. Child called with k=1. If leaf, prints 1+1=2. Correct. So this line is actually logically consistent with the recursive step below IF the initial call is 0. But wait, standard height definition: root is 1. The variable k here acts as "depth from root starting at 0". So height = k + 1. This line seems correct in isolation, but let's check the recursive step.
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
printf("%d\n",n); // @@ The program outputs the number of elements 'n' which is not part of the required output format. This causes Wrong Answer.
for(int i=0;i<n;i++)
{
    scanf("%d",&b);
    p=InitTree(b,p);
}
BintreeFindLeaves(p,k);
return 0;
}