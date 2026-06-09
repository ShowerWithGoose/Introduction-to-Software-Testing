#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100]={0};
struct node{
	int data;
	int floor;
	struct node *lchild,*rchild;
};
typedef struct node Node,*Nodeptr;
Nodeptr root=NULL,p=NULL;
Nodeptr insert(Nodeptr p,int item,int height)
{
	if(p==NULL)
	{		
		p=(Nodeptr)malloc(sizeof(Node));
		p->floor=height;
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
		p->lchild=insert(p->lchild,item,height+1);
	else if(item>=p->data)
		p->rchild=insert(p->rchild,item,height+1);
	return p;
} 
void perorder(Nodeptr p)
{
	if(p!=NULL)
	{
		if(p->lchild==NULL&&p->rchild==NULL)
 			printf("%d %d\n",p->data,p->floor);
 		perorder(p->lchild);
 		perorder(p->rchild);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n); 
	int height=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		root=insert(root,a[i],height);
	}
	perorder(root);
	return 0; 
}

