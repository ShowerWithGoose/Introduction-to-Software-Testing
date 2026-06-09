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
BTNodeptr  insertBST(BTNodeptr p, Datatype value); 
void  destoryTree(BTNodeptr  p);
void  preorder(BTNodeptr root,int height);
int main()
{
    int i,n,value,x;
    scanf("%d",&n);
    BTNodeptr  root=NULL;
    for(i=0; i<n; i++){
         scanf("%d", &value);
         root = insertBST(root, value);
    }
    x=1;
    preorder(root,x);
    destoryTree(root);
    return 0;
}
void  preorder(BTNodeptr root,int height)
{
      if(root!=NULL){
      	if(root->left==NULL&&root->right==NULL){
		  	printf("%d %d\n",root->data,height);
		  }
		preorder(root->left,height+1);
		preorder(root->right,height+1);
       }
}
BTNodeptr  insertBST(BTNodeptr p, Datatype value)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = value;
        p->left = p->right = NULL;
    } 
    else if( value < p->data)
        p->left = insertBST(p->left, value);
    else if( value >= p->data)
       p->right = insertBST(p->right,value);
    return p;
} 
void  destoryTree(BTNodeptr  p)
{
    if(p != NULL)
    {
         destoryTree(p->left);
         destoryTree(p->right);
         free(p);
         p = NULL; 
    }
} 

