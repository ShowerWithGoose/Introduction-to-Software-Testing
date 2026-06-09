#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#define MAXSIZE     100
struct node{
	int count;
	struct node *lchild,*rchild,*parent;
}; 
typedef struct node  *BTNodeptr;
BTNodeptr T=NULL,p,q;
void input(); 
void pre(BTNodeptr,int);
int main(){
	int n; 
	scanf("%d",&n);
	int i,j,record;
	for(i=0;i<n;i++)
	{
		scanf("%d",&record);
		q=(struct node*)malloc(sizeof(struct node));
		q->count=record; 
  		q->lchild = NULL;
  		q->rchild = NULL;
		if(T == NULL)
    	T = p = q;
		else {
			input();
		}     
	}
	pre(T,1);
	return 0;
}
void input()
{
	p=T;
	while(1)
	{
		if((q->count)<(p->count))
		{
			if(p->lchild==NULL){
			p->lchild = q;
			break;
			}
			p=p->lchild;
		}
		if(q->count>=p->count)
		{
			if(p->rchild==NULL){
			p->rchild = q;
			break;
			}
			p=p->rchild;
		}
	}
 }
 void pre(BTNodeptr root,int deep)
{
		     
	if(root->lchild!=NULL)pre(root->lchild,deep+1);
    if(root->rchild!=NULL)pre(root->rchild,deep+1);
	if(root->lchild==NULL&&root->rchild==NULL) {printf("%d %d\n",root->count,deep);}  
} 

