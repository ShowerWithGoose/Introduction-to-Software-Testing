#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree{
	int i;
	int h;//´æ´¢¸ß¶È 
	struct tree *rchild,*lchild;	
};
typedef struct tree *Nodeptr;
typedef struct tree Node;
int k;
Nodeptr insert(Nodeptr p,int a)
{
	if(p==NULL){
		p=(Nodeptr)malloc(sizeof(Node));
		p->i=a;
		p->h=k;
		p->lchild=NULL;p->rchild=NULL; 
	}
	else{
		k++;
		if(a<p->i) 
		p->lchild=insert(p->lchild,a);
		else 
		p->rchild=insert(p->rchild,a);
	}
	return p;
}
void search(Nodeptr p){
	if(p!=NULL){
		search(p->lchild);
		if(p->lchild==NULL&&p->rchild==NULL)
		printf("%d %d\n",p->i,p->h);
		search(p->rchild);
	}
}
int main()
{
	int n,j;
	Nodeptr root=NULL;
	scanf("%d",&n);
	for(;n>0;n--){
		k=1;
		scanf("%d",&j);
		root=insert(root,j);
	}
	search(root);
 } 

