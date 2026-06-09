#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef int Datatype;int a=1;

struct node {
    Datatype data;
    struct node *lchild, *rchild;
    int high;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item,int a);
void printtree(BTNodeptr p);
int main(){

    int i, item; 
    BTNodeptr  root=NULL;
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++){ 
         scanf("%d", &item);int r=1;
         root = insertBST(root, item,r);
        
     }printtree(root);
    return 0;
}

BTNodeptr  insertBST(BTNodeptr p, Datatype item,int a)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;p->high=a;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->data)
        p->lchild = insertBST(p->lchild, item,a+1);
    else if( item >=p->data)
       p->rchild = insertBST(p->rchild,item,a+1);
    
    return p;
} 
void printtree(BTNodeptr p){
	if(p->lchild!=NULL){
		printtree( p->lchild);
	}
		if(p->rchild!=NULL){
			printtree( p->rchild);
		}
		if(p->lchild==NULL&&p->rchild==NULL){
			printf("%d %d\n",p->data,p->high);
		}
}

