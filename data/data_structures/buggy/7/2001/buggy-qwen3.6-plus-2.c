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
        p->left=p->right=NULL; // @@ Missing 'return p;' statement here, causing a compilation error as the non-void function does not return the newly allocated node.
    }
    else if(data<root->data){
        root->left=insNode(root->left,data);
    }
    else {
        root->right=insNode(root->right,data);
    }
    } // @@ Missing 'return root;' statement here before the function ends, causing a compilation error because the function must return a pointer value.
void printLeafNode(struct BstNode *root,int height){
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
     printLeafNode(root,1);

return 0;
}