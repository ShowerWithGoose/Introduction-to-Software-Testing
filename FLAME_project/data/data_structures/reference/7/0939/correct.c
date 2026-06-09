#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef int Datatype;
struct node {
    Datatype data;
    Datatype height;
    struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item ,Datatype sign);
void f(BTNodeptr t);
int main()
{
    int i,n,sign=1,item;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++){ 
         scanf("%d", &item);
         root = insertBST(root, item,sign);
     }
    f(root);
    return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item,Datatype sign)
{
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->height=sign;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->data){
    	sign++;
    	p->lchild = insertBST(p->lchild,item,sign);	
	}
    else if( item >=p->data){
    	sign++;
    	p->rchild = insertBST(p->rchild,item,sign);
	}
    return p;
} 
void f(BTNodeptr t){
	if(t!=NULL){
		if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->data,t->height);
		f( t->lchild);
		f( t->rchild);
	}
}



