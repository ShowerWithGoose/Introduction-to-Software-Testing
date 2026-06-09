#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}bstnode;
typedef struct node*tree;
tree insertBST(tree p,int j);
void leaf(tree root,int height);
int main()
{
    int n,i,j;
    scanf("%d",&n);
    tree root=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&j);
        root=insertBST(root,j);
    }
    leaf(root,1);
return 0;
}
tree insertBST(tree p,int j)
{
    if(p==NULL){
        p=(tree)malloc(sizeof(bstnode));
        p->data=j;
        p->left=p->right=NULL;
    } 
    else if(j<p->data)
        p->left=insertBST(p->left,j);
    else if(j>p->data)
       p->right=insertBST(p->right,j);  
    return p;
} // @@ [The insertion logic does not handle the case where j == p->data. According to the problem, right child should be used for values >= root, but this code only inserts to the right when j > p->data, so duplicate values (like the second 100) are ignored and not inserted into the tree.]
void leaf(tree root,int height){
    if(root==NULL) return; // @@ [Missing null check before accessing root->left and root->right. When the tree is empty or during recursion on non-existent children, this causes undefined behavior. However, in this specific test case, the main issue is the missing duplicate handling above, but this function also lacks a guard clause for NULL root which is good practice and may cause issues in other cases. But more critically, since duplicates are not inserted due to the bug above, the leaf node '100' (the duplicate) is missing from output.]
    if(root->left==NULL && root->right==NULL){
        printf("%d %d\n",root->data,height);
        return;
    }
        if(root->left!=NULL)
        leaf(root->left,height+1);
        if(root->right!=NULL)
        leaf(root->right,height+1);
}