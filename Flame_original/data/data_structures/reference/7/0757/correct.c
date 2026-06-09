#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
	int depth;
};
int mark;//Ñ­»·´ÎÊý 
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr Root=NULL;
void insertBST(int);
void perorder(BTNodeptr);
int main()
{
	int n,j,a;
	scanf("%d",&n);
	for(j=0;j<n;j++){
		scanf("%d",&a);
		insertBST(a);
	}
	perorder(Root);
}
void insertBST(int a)
{
	mark=1;
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->data=a;
	p->left=p->right=NULL;
	q=Root;
	if(q==NULL)
	{
		Root=p;
		Root->depth=1;
	}
	else{
		while(1){
			mark++;
			if(a<q->data){
				if(q->left==NULL)
				{
					q->left=p;
					p->depth=mark;
					break;
				}
				else
					q=q->left;
			}
			else{
				if(q->right==NULL){
					q->right=p;
					p->depth=mark;
					break;
				}
				else
					q=q->right;
			}
		}
	}
}
void perorder(BTNodeptr t)
{
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->data,t->depth);
		perorder(t->left);
		perorder(t->right);
	}
}


