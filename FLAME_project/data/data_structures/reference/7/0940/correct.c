#include<stdio.h>
#include<string.h>
#include<math.h>
#include<memory.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
struct node *left,*right;
int depth;
int num;
}Tree;
Tree *Leaf(Tree *root,int temp,int lenth);
void print(Tree *root);
int main(){
Tree *root=NULL;
int i,n,temp;
scanf("%d",&n);
for(i=0;i<n;i++){
    scanf("%d",&temp);
    int lenth=0;
    root=Leaf(root,temp,lenth);
}
print(root);
return 0;
}
Tree *Leaf(Tree *root,int temp,int lenth){
lenth++;
if(root==NULL){
    root=(Tree *)malloc(sizeof(Tree));
    root->num=temp;
    root->left=root->right=NULL;
    root->depth=lenth;
}
else if(temp<root->num)
    root->left=Leaf(root->left,temp,lenth);
else if(temp>=root->num)
    root->right=Leaf(root->right,temp,lenth);
return root;
}
void print(Tree *root){
if(root){
    if((root->left==NULL)&&(root->right==NULL))
        printf("%d %d\n",root->num,root->depth);
    print(root->left);
    print(root->right);
}
}

