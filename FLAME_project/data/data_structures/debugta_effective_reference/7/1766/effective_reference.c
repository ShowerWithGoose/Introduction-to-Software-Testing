#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int n=1;
typedef int Datatype;
struct node {
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr root, Datatype num); 
void  destoryTree(BTNodeptr  root);
void  preorder(BTNodeptr t,int height);
int main()
{
    int i,n,num,x;
    scanf("%d",&n);
    BTNodeptr  root=NULL;
    for(i=0; i<n; i++){
         scanf("%d", &num);
         root = insertBST(root, num);
    }
    x=1;
    preorder(root,x);
    destoryTree(root);
    return 0;
}
void  preorder(BTNodeptr t,int height)
{
      if(t!=NULL){
      	if(t->left==NULL&&t->right==NULL){
		  	printf("%d %d\n",t->data,height);
		  }
		preorder(t->left,height+1);
		preorder(t->right,height+1);
       }
}
BTNodeptr  insertBST(BTNodeptr root, Datatype num)
{
    if(root == NULL){
        root = (BTNodeptr)malloc(sizeof(BTNode));
        root->data = num;
        root->left = root->right = NULL;
    } 
    else if( num < root->data)
        root->left = insertBST(root->left, num);
    else if( num >= root->data)
       root->right = insertBST(root->right,num);
    return root;
} 
void  destoryTree(BTNodeptr  root)
{
    if(root != NULL)
    {
         destoryTree(root->left);
         destoryTree(root->right);
         free(root);
         root = NULL; 
    }
} 

