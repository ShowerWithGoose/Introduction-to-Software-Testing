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
} // @@ [The insertion logic does not handle the case where j == p->data. According to the problem, right child should be used for values >= root, but this code only inserts to the right when j > p->data, thus ignoring duplicate values like the second 100 in the input. As a result, the duplicate 100 is never inserted, causing a missing leaf node in the output.]

void leaf(tree root,int height){
    if(root==NULL) return; // @@ [The original function assumes root is never NULL when called, but after fixing insertion, or even in edge cases (like n=0), root could be NULL. However, more critically, in the current buggy version, this function crashes if root is NULL because it accesses root->left/right without checking. But in this specific test case, root isn't NULL. The primary bug is in insertion, but this function also lacks a NULL check at the start, which is good practice and required if insertion were fixed. However, the immediate cause of the wrong answer is the missing duplicate handling in insertBST. Still, the leaf function as written will crash if called on an empty tree, but that's not the issue here. The real issue is the missing duplicate. So the main error is in insertBST.]
    if(root->left==NULL && root->right==NULL){
        printf("%d %d\n",root->data,height);
        return;
    }
        if(root->left!=NULL)
        leaf(root->left,height+1);
        if(root->right!=NULL)
        leaf(root->right,height+1);
}