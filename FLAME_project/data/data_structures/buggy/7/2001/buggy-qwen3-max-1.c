#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct BstNode{
    int data;
    struct BstNode *left,*right;
};
struct BstNode *insNode(struct BstNode *root,int data){
    struct BstNode *p;
    if(root == NULL){
        p=(struct BstNode *)malloc(sizeof(struct BstNode));
        p->data=data;
        p->left=p->right=NULL;
        return p; // @@ [Missing return statement when root is NULL, causing undefined behavior]
    }
    else if(data<root->data){
        root->left=insNode(root->left,data);
    }
    else {
        root->right=insNode(root->right,data);
    }
    return root; // @@ [Missing return statement at the end of the function, leading to undefined behavior when root is not NULL]
}
void printLeafNode(struct BstNode *root,int height){
    if(root==NULL) return; // @@ [Missing null check at the beginning of the function, causing segmentation fault when root is NULL]
    if(root->left!=NULL)
    printLeafNode(root->left,height+1);
    if(root->right!=NULL)
    printLeafNode(root->right,height+1);
    if(root->left==NULL&&root->right==NULL){
        printf("%d %d\n",root->data,height);
    }
}
int main()
{
     struct  BstNode *root=NULL;
     int n,data,i;
     scanf("%d",&n);
     for(i=0;i<n;i++){
         scanf("%d",&data);
         {
             root=insNode(root,data);
         }
     }
     if(root != NULL) // @@ [Missing null check before calling printLeafNode; if n=0 or tree is empty, passing NULL causes crash]
     printLeafNode(root,1);

return 0;
}