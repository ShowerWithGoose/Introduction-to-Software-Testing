#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p,int x);
void printLeafNode(BTNodeptr p,int hight);
int main()
{
	BTNodeptr p;
	BTNodeptr  root=NULL;
	int i,n,a;
	scanf("%d",&n);
	i=0;
    while(i<n){
    	scanf("%d",&a);
    	root = insertBST(root,a);
    	
        i++;
	}
	printLeafNode(root,1);    
	return 0;
}
BTNodeptr  insertBST(BTNodeptr p, int x)
{
    if(p == NULL){     
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = x;
        p->lchild = p->rchild = NULL;
        
    } 
    else if(x< p->data)
        p->lchild = insertBST(p->lchild,x);
    else 
       p->rchild = insertBST(p->rchild,x);
     
    return p;
} 
void printLeafNode(BTNodeptr p,int hight) 
{    
     if(p->lchild!=NULL) 
            printLeafNode(p->lchild,hight+1); 
     if(p->rchild!=NULL) 
            printLeafNode(p->rchild,hight+1); 
      if(p->lchild==NULL && p->rchild==NULL) 
             printf("%d %d\n",p->data,hight); 
} 


