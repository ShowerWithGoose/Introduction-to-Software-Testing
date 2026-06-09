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
} 
void leaf(tree root,int height){
    if(root==NULL) return; // @@ [The function does not handle the case where root is NULL, leading to potential segmentation fault when accessing root->left or root->right. Also, the traversal order is pre-order but should be in-order to output leaf nodes from left to right as per BST structure.]
    if(root->left==NULL && root->right==NULL){
        printf("%d %d\n",root->data,height);
        return;
    }
        if(root->left!=NULL)
        leaf(root->left,height+1);
        if(root->right!=NULL)
        leaf(root->right,height+1);
}