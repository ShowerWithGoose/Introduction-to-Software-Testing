#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
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
	return 0;
}
void insertBST(int a)
{
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->data=a;
	p->left=p->right=NULL;
	q=Root;
	if(q==NULL)
		Root=p;
	else{
		while(1){
			if(a<q->data){
				if(q->left==NULL){
					q->left=p;
					break;
				}
				else
					q=q->left;
			}
			else{
				if(q->right==NULL){
					q->right=p;
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
	static int i=0;
	i++;
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->data,i);
		perorder(t->left);
		perorder(t->right);
	}
	i--;
}



