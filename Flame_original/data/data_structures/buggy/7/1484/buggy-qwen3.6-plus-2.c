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
    else if(j>p->data) // @@ The problem specifies that the right child's value should be greater than or equal to the root. This condition misses the equal case, causing duplicate values to be ignored. It should be 'else' or 'else if(j>=p->data)'.
       p->right=insertBST(p->right,j);  
    return p;
} 
void leaf(tree root,int height){ // @@ Missing null pointer check for root. If root is NULL (e.g., when n=0), accessing root->left will cause a segmentation fault. Should add 'if(root == NULL) return;' at the beginning.
    if(root->left==NULL && root->right==NULL){
        printf("%d %d\n",root->data,height);
        return;
    }
        if(root->left!=NULL)
        leaf(root->left,height+1);
        if(root->right!=NULL)
        leaf(root->right,height+1);
}