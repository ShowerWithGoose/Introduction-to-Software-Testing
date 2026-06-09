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
BTNodeptr  insertBST(BTNodeptr p, Datatype item); 
void  destoryTree(BTNodeptr  p);
void  preorder(BTNodeptr t,int height);
int main()
{
    int i,n,item,x;
    scanf("%d",&n);
    BTNodeptr  root=NULL;
    for(i=0; i<n; i++){
         scanf("%d", &item);
         root = insertBST(root, item);
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
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->left = p->right = NULL;
    } 
    else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item >= p->data)
       p->right = insertBST(p->right,item);
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

