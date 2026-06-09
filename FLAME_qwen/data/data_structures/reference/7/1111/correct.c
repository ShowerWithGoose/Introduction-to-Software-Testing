#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int depth;
}Tree,*Treep;
int m,i,n,depth=1;
Treep root=NULL;
void VISIT(Treep p)
{
 printf("%d %d\n",p->val,p->depth);
}
void inorder(Treep p)
{
    if(p!=NULL){
        inorder(p->left);
        if(p->left==NULL && p->right==NULL) VISIT(p);      
        inorder(p->right);
    }
}
void InsertBST(Treep *p,int value,int depth);
int main()
{ 
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&m);
  InsertBST(&root,m,1);
 }
 inorder(root);
 return 0;
}

void InsertBST(Treep *p,int value,int depth) 
{
 if(*p==NULL)
 {
  *p=(Treep)malloc(sizeof(Treep));
  (*p)->left=(*p)->right=NULL;
  (*p)->val=value;
  (*p)->depth=depth;
 }
 else if(value<(*p)->val)
 {
  InsertBST(&((*p)->left),value,depth+1);
 } 
 else
 {
  InsertBST(&((*p)->right),value,depth+1);
 } 
}
