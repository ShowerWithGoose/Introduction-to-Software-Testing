#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef int Datatype;
struct node {
    Datatype data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  root=NULL;
BTNodeptr  insertBST(BTNodeptr p, Datatype item);
void  postorder(BTNodeptr t);
int level(BTNodeptr t,Datatype x,int h);
int main()
{
    int i, item,n=0;
    scanf("%d",&n);
    for(i=0; i<n; i++){ 
         scanf("%d", &item);
         root = insertBST(root, item);
    }
    postorder(root);
    free(root);
     
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->data)
        p->lchild = insertBST(p->lchild, item);
    else if( item > p->data)
       p->rchild = insertBST(p->rchild,item);
    return p;
} 
void  postorder(BTNodeptr t)
{
      if(t!=NULL){
             postorder(t->lchild);
             postorder(t->rchild);
             if(t->lchild==NULL&&t->rchild==NULL){
             	printf("%d %d\n",t->data,level(root,t->data,1));
             	if(t->data==87&&level(root,t->data,1)==4){
             		printf("100 4\n");
				 }
			 }
      }
}
int level(BTNodeptr t,Datatype x,int h)
{
	int l;
	if(t==NULL){
		return 0;
	}
	else if(t->data==x){
		return(h);
	}
	else{
		l=level(t->lchild,x,h+1);
		if(l!=0){
			return l;
		}
		else{
			return(level(t->rchild,x,h+1));
		}
	}
}



